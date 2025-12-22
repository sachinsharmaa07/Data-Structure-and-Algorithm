#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Helper function to check if two frequency arrays are equal
bool matches(const vector<int>& s1map, const vector<int>& s2map) {
    for (int i = 0; i < 26; ++i) {
        if (s1map[i] != s2map[i]) return false;
    }
    return true;
}

// Function to check if s2 contains a permutation of s1
bool checkInclusion(string s1, string s2) {
    int len1 = s1.size(), len2 = s2.size();
    if (len1 > len2) return false;

    vector<int> s1map(26, 0), s2map(26, 0);

    for (int i = 0; i < len1; ++i) {
        s1map[s1[i] - 'a']++;
        s2map[s2[i] - 'a']++;
    }

    for (int i = 0; i <= len2 - len1; ++i) {
        if (matches(s1map, s2map)) return true;
        if (i + len1 < len2) {
            s2map[s2[i] - 'a']--;
            s2map[s2[i + len1] - 'a']++;
        }
    }
    return false;
}

int main() {
    string s1, s2;
    cout << "Enter s1: ";
    cin >> s1;
    cout << "Enter s2: ";
    cin >> s2;

    if (checkInclusion(s1, s2)) {
        cout << "s2 contains a permutation of s1." << endl;
    } else {
        cout << "s2 does NOT contain a permutation of s1." << endl;
    }

    return 0;
}