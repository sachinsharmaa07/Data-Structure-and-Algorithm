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
    int solve2(int n,vector<int>& nums){
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int rob=nums[i];
            if(i>1){
             rob=nums[i]+prev2;
            }
            int skip=0+prev;
            int curr=max(rob,skip);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    int main() {
        vector<int> nums={1,2,3,1};
        vector<int> dp(nums.size(),-1);
       cout<<min(solve(0,nums,dp),solve2(nums.size(),nums))<<endl;
    }
