#include<iostream>
#include<vector>
using namespace std;
 int fibo(int n,vector<int>&dp) {
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=fibo(n-1,dp)+fibo(n-2,dp);
        return dp[n];

    }
    int main(){
        vector<int> dp(11,-1);
        cout<< fibo(10,dp);
    }
