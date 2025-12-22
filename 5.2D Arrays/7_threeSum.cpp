#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
  vector<vector<int>> threeSumBF(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1;k<nums.size();k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>trip={nums[i],nums[j],nums[k]};
                        sort(trip.begin(),trip.end());
                        if(s.find(trip)==s.end()){
                            s.insert(trip);
                            ans.push_back(trip);
                            
                        }
                    }

                }
            }
        }
return ans;
}
vector<vector<int>> threeSumBetter(vector<int>& nums) {
        set<vector <int>>unique;
        for(int i=0;i<nums.size();i++){
            int target=-nums[i];
            set<int>s;
            for(int j=i+1;j<nums.size();j++){
                int third=target-nums[j];
                if(s.find(third)!=s.end()){
                    vector<int> trip ={nums[i],nums[j],third};
                    sort(trip.begin(),trip.end());
                    unique.insert(trip);
                }
                s.insert(nums[j]);
            }
        }
        vector<vector<int>> ans(unique.begin(),unique.end());
        return ans;
    }
 vector<vector<int>> threeSum2pointerApproach(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int j=i+1;int k=nums.size()-1;
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1]){
                        j++;
                    }
                }
            }
        }
        return ans;
    }
int main(){
    vector<int>nums={-1,0,1,2,-1,-4};
    vector<vector<int>>ans=threeSum2pointerApproach(nums);
    vector<vector<int>>ans1=threeSumBF(nums);
    vector<vector<int>>ans2=threeSumBetter(nums);
    for(auto v:ans){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;cout<<endl;
    for(auto v:ans1){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    cout<<endl;cout<<endl;cout<<endl;
    for(auto v:ans2){
        for(auto x:v){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}
