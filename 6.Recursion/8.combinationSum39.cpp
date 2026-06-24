#include<iostream>
#include<vector>
#include<set>
using namespace std;
set<vector<int>> s;
   
void helper(vector<int>& arr, int idx,int target ,vector<vector<int>> &ans,vector<int> &combin){
        if(idx==arr.size() || target<0){
            return;
        }
        if(target==0){
            if(s.find(combin)==s.end()){
 ans.push_back({combin});
                s.insert(combin);
            }
           
        }
        combin.push_back(arr[idx]);
        helper(arr,idx+1,target-arr[idx],ans,combin);
        helper(arr,idx,target-arr[idx],ans,combin);
        combin.pop_back();

        helper(arr,idx+1,target,ans,combin);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combin;
        helper(candidates,0,target,ans ,combin);
        return ans;


        
    }
int main(){
    vector<int> candidates={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> result=combinationSum(candidates,target);
    for(auto vec: result){
        for(auto num: vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;

}