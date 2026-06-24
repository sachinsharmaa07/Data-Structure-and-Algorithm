#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
void getall(vector<int>&nums, vector<int>&ans,int i,vector<vector<int>> &all){
        if(i==nums.size()){
            all.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        getall(nums,ans,i+1,all);
        ans.pop_back();
        int index=i+1;
        while(index<nums.size() && nums[index]==nums[index-1]){
            index++;
        }
        getall(nums,ans,index,all);
        


    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> all;
        vector<int>ans;
        getall(nums,ans,0,all);
        return all;
    }
int main(){
    vector<int> nums={1,2,3,1,2,3,1,3,2,1,2,3,2,1,3};
    vector<vector<int>> ans=subsetsWithDup(nums);
    for(vector<int> x : ans){
        for(int y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    
}