#include<iostream>
using namespace std;
    int main() {
    vector<int> cost={10,15,20};
    int n=cost.size();
    vector<int>dp(n);
    dp[0]=cost[0];
    dp[1]=cost[1];
     for(int i=2;i<=cost.size();i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
     }
    cout<< min(dp[n-1],dp[n-2]);
    //or space optimization
    
   int  prev2=cost[0];
    int prev1=cost[1];
   int  curr=0;
     for(int i=2;i<n;i++){
        curr=cost[i]+min(prev1,prev2);
        prev2=prev1;
        prev1=curr;
     }
    cout<<min(prev1,prev2);
    }