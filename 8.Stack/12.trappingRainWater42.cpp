#include <vector>
using namespace std;
#include<iostream>
int trapBruteForce(vector<int>& height) {
        int ans=0;
        int l=0;
        for(int i=0;i<height.size();i++){
            l=max(l,height[i]);
            int r=0;
            for(int j=height.size()-1;j>i;j--){
                r=max(r,height[j]);
            }
            ans+=max(min(l,r)-height[i],0);

        }
        return ans;
    }
int trapBetter(vector<int>& height) {
        int x=height.size();
        int ans=0;
        vector<int>l(x);
        vector<int>r(x);
        l[0]=height[0];
        r[x-1]=height[x-1];
        for(int i=1;i<x;i++){
            l[i]=max(l[i-1],height[i]);
        }
        for(int i=x-2;i>=0;i--){
            r[i]=max(r[i+1],height[i]);
        }
        for(int i=0;i<x;i++){
            ans+=max(min(l[i],r[i])-height[i],0);

        }
        return ans;
    }
int trapBestOptimal(vector<int>& height) {
        int x=height.size();
        int ans=0;
        int l=0,r=x-1;
        int rmax=0,lmax=0;
        while(l<r){
            rmax=max(rmax,height[r]);
            lmax=max(lmax,height[l]);
            if(lmax<rmax){
                ans+=max(0,lmax-height[l++]);
            }
            else{
                ans+=max(0,rmax-height[r--]);
            }
        }

        return ans;
    }
int main(){
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trapBruteForce(height);
}