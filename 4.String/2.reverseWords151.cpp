#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    string ans = "";
    int x = s.length();
    for (int i = 0; i < x; i++) {
        // Skip spaces
        if (s[i] == ' ') continue;
        string word = "";
        // Collect the word
        while (i < x && s[i] != ' ') {
            word += s[i];
            i++;
        }
        reverse(word.begin(), word.end());
        if (!ans.empty()) ans += " ";
        ans += word;
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    cout << reverseWords(s) << endl;
    return 0;
}
