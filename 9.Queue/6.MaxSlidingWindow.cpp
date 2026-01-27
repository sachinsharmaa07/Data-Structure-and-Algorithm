#include<iostream>
using namespace std;
#include<vector>
#include<deque>
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        vector<int>res;
        for(int i=0;i<k;i++){
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k;i<nums.size();i++){
            res.push_back(nums[dq.front()]);
            while(dq.size()>0 && dq.front()<=i-k){
                dq.pop_front();
            }
            while(dq.size()>0 && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;

    }
int main(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int>res=maxSlidingWindow(nums,k);
    for(int i=0;i<res.size();i++){  
        cout<<res[i]<<" ";
    }
}