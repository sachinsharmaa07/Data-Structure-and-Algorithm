#include<iostream>
#include<vector>
using namespace std;
    int solve(int i,vector<int>& nums,vector<int>&dp){
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int rub=nums[i]+solve(i+2,nums,dp);
        int skip=solve(i+1,nums,dp);
        return dp[i]= max(rub,skip);
    }
    int main() {
        vector<int> nums={1,2,3,1};
        vector<int> dp(nums.size(),-1);
        cout<< solve(0,nums,dp);
    }
