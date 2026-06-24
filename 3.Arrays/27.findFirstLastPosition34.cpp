#include<iostream>  
using namespace std;    

vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        
        int l=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int u=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(l==nums.size() || nums[l]!=target){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(l);
        ans.push_back(u-1);
        return ans;
    }
    int lowerBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
    int UpperBound(vector<int>& arr, int target) {
    int low = 0, high = arr.size();

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] > target)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}
int main(){
    vector<int> arr={5,7,7,8,8,10};
    int target=8;
    vector<int> res=searchRange(arr,target);
    cout<<"First and Last Occurrence of "<<target<<" is : ["<<res[0]<<", "<<res[1]<<"]"<<endl;
}   