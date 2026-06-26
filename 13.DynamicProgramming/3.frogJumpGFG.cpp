 #include <bits/stdc++.h>
 #include <iostream>
 using namespace std;
 int f(vector<int>& h,int n){
        if(n<=0){
            return 0;
        }
        int fs=f(h,n-1)+abs(h[n]-h[n-1]);
        int ls=99999999;
        if(n>1){
            ls=f(h,n-2)+abs(h[n]-h[n-2]);
        }
        return min(ls,fs);
    }
    int f2(vector<int>& h,int n,vector<int>&dp){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int fs=f(h,n-1,dp)+abs(h[n]-h[n-1]);
        int ls=99999999;
        if(n>1){
            ls=f(h,n-2,dp)+abs(h[n]-h[n-2]);
        }
        return dp[n]= min(ls,fs);
    }
    int f3(vector<int>& h,int n,vector<int>&dp){
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int ls=dp[i-1]+abs(h[i]-h[i-1]);
            int rs=9999999;
            if(i>1){
                rs=dp[i-2]+abs(h[i]-h[i-2]);
            }
            dp[i]=min(rs,ls);
        }
        return dp[n];
    }
    int f4(vector<int>& h,int n){
        int prev=0;
        int prev2=0;
        for(int i=1;i<=n;i++){
            int ls=prev+abs(h[i]-h[i-1]);
            int rs=9999999;
            if(i>1){
                rs=prev2+abs(h[i]-h[i-2]);
            }
            int curr=min(rs,ls);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }

    int main(){
        int n=h.size();
        int ans1=f(h,n-1);
        int ans2=f2(h,n,dp);
        int ans3=f3(h,n,dp);
        int ans4=f4(h,n);
        cout<<ans1<<" "<<ans2<<" "<<ans3<<" "<<ans4;
    }