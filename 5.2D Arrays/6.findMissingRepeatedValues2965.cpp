#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_set<int> s;
        vector<int> ans;
        int a,b;int sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum+=grid[i][j];
                if(s.find(grid[i][j])!=s.end()){
                    a=grid[i][j];
                    ans.push_back(grid[i][j]);
                }
                s.insert(grid[i][j]);
        
            }
        }
        int asum=((n*n) *((n*n)+1))/2;
        b=asum+a-sum;
        ans.push_back(b);
        return ans;
        
    }
int main(){
   vector<vector<int>>grid={{1,2,2},{3,4,5},{6,7,8}};
   vector<int>ans=findMissingAndRepeatedValues(grid);
   for(auto i:ans){
    cout<<i<<" ";
   }
   return 0;
}