#include<iostream>
#include<vector>
using namespace std;
vector<int> pairSum(vector<int>nums,int target){
    int x=nums.size();
    vector<int> res;
    for(int i=0;i<x;i++){
        for(int j=i+1;j<x;j++){
            if(nums[i]+nums[j]==target){

                res.push_back(i);
                res.push_back(j);
            }
        }
    }
    return res;
}
int main(){
    vector<int> vec={2,7,11,15};
    int target=26;
    vector<int> res=pairSum(vec,target);
    cout<<"the result is on these indexes : ";
    for(int i: res){
        cout<<i<<" ";
    }


}