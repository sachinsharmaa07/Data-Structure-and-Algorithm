#include <vector>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// Find next greater element in nums2 for each element in nums1
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> s;
        
        // Build map of next greater elements for all nums2 elements
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (s.size() > 0 && s.top() <= nums2[i]) {
                s.pop();
            }
            if (s.empty()) {
                mp[nums2[i]]=-1;
            } else {
                mp[nums2[i]]=s.top();
            }
            s.push(nums2[i]);
        }
        
        // Changed from ans[nums1.size()] to ans(nums1.size())
        vector<int> ans(nums1.size());
        for(int i=0; i<nums1.size(); i++){
            ans[i]=mp[nums1[i]];
        }
    return ans;
    }
int main() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> result = nextGreaterElement(nums1, nums2);         
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}