#include<iostream>
using namespace std;
 void getperm(vector<int>& nums,int index,vector<vector<int>> &ans){
        if(index==nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            getperm(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getperm(nums,0,ans);
        return ans;

        
    }
    int main(){
        vector<int> nums={1,2,3};
        vector<vector<int>> ans=permute(nums);
        for(vector<int> x:ans){
            for(int i: x){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }