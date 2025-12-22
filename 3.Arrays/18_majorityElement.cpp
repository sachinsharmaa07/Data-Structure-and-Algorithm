#include <iostream>
#include <vector>
#include <algorithm>//used for sort function
using namespace std;

int majorityElement(vector<int>& nums) {
    int x = nums.size();
    if (x == 1) return nums[0];  // Handle single-element case

    sort(nums.begin(), nums.end());
    int freq = 1;
    int y = x / 2;

    for (int i = 0; i < x - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            freq++;
        } else {
            freq = 1;
        }

        if (freq > y) {
            return nums[i];
        }
    }

    return 0; // Only if no majority found (shouldn't happen if one always exists)
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2,3,4,4,4,4,4,4,4,4,4,4,4};  // Test case
    int result = majorityElement(nums);
    cout << "Output: " << result << endl;  // Expected: 2
    return 0;
}
