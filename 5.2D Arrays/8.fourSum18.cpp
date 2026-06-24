#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();){
                int p=j+1;int q=nums.size()-1;
                while(p<q){
long long sum=(long long)nums[i]+(long long)nums[j]+(long long)nums[p]+(long long)nums[q];
                    if(sum<target)p++;
                    else if(sum>target)q--;
                    else{
                 ans.push_back({nums[i],nums[j],nums[p],nums[q]});
                 p++;q--;
                 while(p<q && nums[p]==nums[p-1])p++;


                    }
                
                }
                j++;
            while(j<nums.size() && nums[j]==nums[j-1])j++;
            }
            
    

        }
        return ans;
    }
int main(){
    vector<int>nums={1,0,-1,0,-2,2};
    int target=0;
    vector<vector<int>>ans=fourSum(nums,target);
    for(auto v:ans){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return 0;
}