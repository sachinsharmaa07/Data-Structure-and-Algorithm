#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int index = 0;
        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;
            while (i < n && chars[i] == ch) {
                count++; i++;
            }
            if (count == 1) {
                chars[index++] = ch;
            } else {
                chars[index++] = ch;
                string str = to_string(count);
                for (char c : str) {
                    chars[index++] = c;
                }
            }
            i--;
        }
        chars.resize(index);
        return chars.size();
    }
};

int main() {
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    Solution sol;
    int newLength = sol.compress(chars);

    cout << "Compressed length: " << newLength << endl;
    cout << "Compressed chars: ";
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}