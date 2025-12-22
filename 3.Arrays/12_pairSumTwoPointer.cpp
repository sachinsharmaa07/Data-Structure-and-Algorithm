#include<iostream>
#include<vector>
using namespace std;
vector<int> pairSum(vector<int>nums,int target){
    int x=nums.size();
    vector<int> res;
    int st=0;int end=x-1;
    while(end>st){
        int m=nums[st]+nums[end];
        if(m>target){
            end--;
        }
        else if(m<target){
            st++;
        }
        else{
            res.push_back(st);
            res.push_back(end);
            return res;
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