#include <iostream>
#include <vector>
using namespace std;

// Moore's Voting Algorithm as a normal function
int majorityElement(vector<int>& nums) {
    int ans = 0, freq = 0;
    for (int i : nums) {
        if (freq == 0) {
            ans = i;
        }
        if (ans == i) {
            freq++;
        } else {
            freq--;
        }
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};  // Test case
    int result = majorityElement(nums);
    cout << "Output: " << result << endl;  // Expected: 2
    return 0;
}
