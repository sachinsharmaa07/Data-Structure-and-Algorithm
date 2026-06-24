#include <iostream>
using namespace std;
int binarySearch(vector<int> &arr, int st, int end, int key) {
    if (st > end) return -1;
    int mid = st + (end - st) / 2;
    if (arr[mid] == key) return mid;
    return arr[mid] < key
        ? binarySearch(arr, mid + 1, end, key)
        : binarySearch(arr, st, mid - 1, key);
}
    int search(vector<int>& nums, int target) {
        int st=0;int end=nums.size()-1;
        int ans=binarySearch(nums,0,end,target);
        return ans;
        
    }

int main() {
    int n=10;
    vector<int>arr={1,2,3,4,5,6,7,8,9,10};
    int key=5;
    cout<<search(arr,key);
    return 0;   
}
