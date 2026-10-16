#!/usr/bin/env python3
"""Sync recent public LeetCode accepted submissions into repository progress files.

Uses LeetCode's unofficial public GraphQL endpoint. The public recent-accepted
feed is limited; this script records what it sees and deduplicates problems.
It does not fetch or publish source code.
"""
from __future__ import annotations

import json
import os
import sys
import time
from collections import Counter, defaultdict
from datetime import datetime, timezone
from pathlib import Path
from urllib.request import Request, urlopen
from urllib.error import URLError, HTTPError

ROOT = Path(__file__).resolve().parents[1]
USERNAME = os.environ.get("LEETCODE_USERNAME", "sachinsharmaa07")
HISTORY_PATH = ROOT / "leetcode_progress.json"
DAILY_LOG_PATH = ROOT / "progress.md"
README_PATH = ROOT / "README.md"
README_START = "<!-- LEETCODE_PROGRESS_START -->"
README_END = "<!-- LEETCODE_PROGRESS_END -->"
SQL_LANGS = {"mysql", "mssql", "oraclesql", "postgresql", "sql"}
ENDPOINT = "https://leetcode.com/graphql"

QUERY = """
query recentAccepted($username: String!) {
  recentAcSubmissionList(username: $username, limit: 20) {
    title
    titleSlug
    timestamp
    lang
  }
}
"""

def fetch_recent(retries: int = 3, backoff_factor: float = 2.0):
    payload = json.dumps({"query": QUERY, "variables": {"username": USERNAME}}).encode()
    request = Request(
        ENDPOINT,
        data=payload,
        headers={
            "Content-Type": "application/json",
            "User-Agent": "leetcode-github-progress-sync/1.0",
            "Referer": "https://leetcode.com/",
        },
        method="POST",
    )
    last_err = None
    for attempt in range(1, retries + 1):
        try:
            with urlopen(request, timeout=25) as response:
                body = json.loads(response.read().decode("utf-8"))
            if body.get("errors"):
                raise RuntimeError("LeetCode GraphQL returned an error: " + json.dumps(body["errors"]))
            submissions = (body.get("data") or {}).get("recentAcSubmissionList")
            if submissions is None:
                raise RuntimeError("LeetCode response did not contain recentAcSubmissionList.")
            return submissions
        except (HTTPError, URLError, TimeoutError, RuntimeError) as exc:
            last_err = exc
            if attempt < retries:
                wait_time = backoff_factor ** attempt
                print(f"Warning: LeetCode request attempt {attempt} failed ({exc}). Retrying in {wait_time:.1f}s...")
                time.sleep(wait_time)
            else:
                break
    raise RuntimeError(f"Could not reach LeetCode public endpoint after {retries} attempts: {last_err}") from last_err

def category_for(lang):
    normalized = (lang or "").strip().lower().replace(" ", "")
    return "SQL" if normalized in SQL_LANGS or "sql" in normalized else "DSA"

def read_history():
    if not HISTORY_PATH.exists():
        return {"username": USERNAME, "problems": []}
    try:
        data = json.loads(HISTORY_PATH.read_text(encoding="utf-8"))
    except json.JSONDecodeError as exc:
        raise RuntimeError(f"{HISTORY_PATH.name} is not valid JSON; refusing to overwrite it.") from exc
    if not isinstance(data, dict) or not isinstance(data.get("problems"), list):
        raise RuntimeError(f"{HISTORY_PATH.name} has an unexpected format; refusing to overwrite it.")
    data.setdefault("username", USERNAME)
    return data

def iso_date(timestamp):
    return datetime.fromtimestamp(int(timestamp), tz=timezone.utc).date().isoformat()

def problem_key(item):
    return f'{item["category"]}:{item["titleSlug"]}'

def make_readme_section(problems):
    counts = Counter(p["category"] for p in problems)
    dsa = counts.get("DSA", 0)
    sql = counts.get("SQL", 0)
    total = len({problem_key(p) for p in problems})
    lines = [
        README_START,
        "## 📊 LeetCode Progress (automatically synced)",
        "",
        f"- **Tracked accepted problems:** {total}",
        f"- **DSA:** {dsa}",
        f"- **SQL:** {sql}",
        f"- **LeetCode profile:** https://leetcode.com/u/{USERNAME}/",
        f"- **Daily log:** [progress.md](progress.md)",
        "",
        "> This section counts unique accepted problems observed by this repository's sync. "
        "The public LeetCode feed only exposes a limited number of recent accepted submissions, "
        "so this is not guaranteed to be your complete historical LeetCode total.",
        README_END,
    ]
    return "\n".join(lines)

def update_readme(problems):
    section = make_readme_section(problems)
    if README_PATH.exists():
        content = README_PATH.read_text(encoding="utf-8")
    else:
        content = "# Data Structure and Algorithm\n"
    if README_START in content and README_END in content:
        start = content.index(README_START)
        end = content.index(README_END, start) + len(README_END)
        content = content[:start] + section + content[end:]
    else:
        content = content.rstrip() + "\n\n" + section + "\n"
    README_PATH.write_text(content, encoding="utf-8")

def update_daily_log(all_problems, new_items):
    """Update progress.md cleanly without creating duplicate date headings."""
    if not DAILY_LOG_PATH.exists():
        # Build initial log grouped cleanly by date in chronological order
        grouped = defaultdict(list)
        for item in all_problems:
            grouped[item["date"]].append(item)
        lines = [
            "# Daily LeetCode Progress",
            "",
            f"> Automatically tracked accepted submissions for [@{USERNAME}](https://leetcode.com/u/{USERNAME}/).",
            "",
        ]
        for day in sorted(grouped.keys()):
            lines.append(f"## {day}")
            for item in sorted(grouped[day], key=lambda x: (x["category"], x["title"].lower())):
                url = f'https://leetcode.com/problems/{item["titleSlug"]}/'
                lines.append(f'- **{item["category"]}:** [{item["title"]}]({url}) — `{item["lang"]}`')
            lines.append("")
        DAILY_LOG_PATH.write_text("\n".join(lines).rstrip() + "\n", encoding="utf-8")
        return

    if not new_items:
        return

    content = DAILY_LOG_PATH.read_text(encoding="utf-8")
    grouped = defaultdict(list)
    for item in new_items:
        grouped[item["date"]].append(item)

    # For each date in new_items, if section exists, insert lines before next section; otherwise append section.
    for day in sorted(grouped.keys()):
        header = f"## {day}"
        item_lines = [
            f'- **{item["category"]}:** [{item["title"]}](https://leetcode.com/problems/{item["titleSlug"]}/) — `{item["lang"]}`'
            for item in sorted(grouped[day], key=lambda x: (x["category"], x["title"].lower()))
        ]
        items_block = "\n".join(item_lines)

        if header in content:
            # Insert under existing header
            header_idx = content.index(header)
            next_header_idx = content.find("\n## ", header_idx + len(header))
            if next_header_idx != -1:
                content = (
                    content[:next_header_idx].rstrip()
                    + "\n"
                    + items_block
                    + "\n"
                    + content[next_header_idx:]
                )
            else:
                content = content.rstrip() + "\n" + items_block + "\n"
        else:
            section_block = f"{header}\n{items_block}\n"
            content = content.rstrip() + "\n\n" + section_block

    DAILY_LOG_PATH.write_text(content.rstrip() + "\n", encoding="utf-8")

def main():
    recent = fetch_recent()
    history = read_history()
    existing = {problem_key(p) for p in history["problems"]}
    new_items = []
    for raw in recent:
        if not raw or not raw.get("titleSlug") or not raw.get("timestamp"):
            continue
        category = category_for(raw.get("lang"))
        item = {
            "title": raw.get("title") or raw["titleSlug"],
            "titleSlug": raw["titleSlug"],
            "timestamp": int(raw["timestamp"]),
            "date": iso_date(raw["timestamp"]),
            "lang": raw.get("lang") or "unknown",
            "category": category,
        }
        key = problem_key(item)
        if key not in existing:
            existing.add(key)
            history["problems"].append(item)
            new_items.append(item)

    history["username"] = USERNAME
    history["lastSyncedAt"] = datetime.now(timezone.utc).isoformat(timespec="seconds")
    history["problems"].sort(key=lambda p: (p.get("timestamp", 0), p.get("title", "").lower()))
    HISTORY_PATH.write_text(json.dumps(history, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    update_daily_log(history["problems"], new_items)
    update_readme(history["problems"])

    print(f"Fetched {len(recent)} recent accepted submissions.")
    print(f"Added {len(new_items)} previously untracked problems.")
    print(f"History now contains {len({problem_key(p) for p in history['problems']})} unique tracked problems.")

if __name__ == "__main__":
    try:
        main()
    except Exception as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        sys.exit(1)
