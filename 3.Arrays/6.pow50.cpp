#include<iostream>
using namespace std;
int binExp(double x,int n){
        if(x==0)return 0;
        if(n==0)return 1.0;
        long bf=n;
        if(n<0){
            x=1/x;
            bf=-bf;
        }
        double ans=1;
        while(bf>0){
            if(bf%2==1){
                ans*=x;
            }
            x*=x;
            bf/=2;
        }
        return ans;
    }
int main(){
    int x=3;
    int y=5;
    int m=binExp(3.0,5);
    cout<<x<<" raised to power "<<y<<" is "<<m;
    
}