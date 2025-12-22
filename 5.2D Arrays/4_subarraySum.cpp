#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int subarraySumBF(vector<int>& nums, int k) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=i;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k){
                    count++;
                }

            }
        }
        return count;
    }
int subarraySumOptimal(vector<int>& nums, int k) {
        int count=0;int n =nums.size();
        vector<int> ps(n,0);
        unordered_map<int,int>m;
        ps[0]=nums[0];
        int i=1;
        for(int j=0;j<n;j++){
            
            if(j>0 ){
                ps[i]=ps[i-1]+nums[i];
                i++;
            }
            if(ps[j]==k)count++;
            int val=ps[j]-k;
            if(m.find(val)!=m.end()){
                count+=m[val];
            }
            m[ps[j]]++;   
        }
        return count;
}
int main(){
    vector<int>nums={1,1,1};
    int k=2;
    cout<<subarraySumOptimal(nums,k);cout<<endl;
    cout<<subarraySumBF(nums,k);
    return 0;
}      