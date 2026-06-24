#include<iostream>
using namespace std;
int main(){
    int p[]={1,-2,3,4,-1,0,5,-6};
    int curr=1;int maxi=1;
    for(int i=0;i<8;i++){
        curr=p[i]*curr;
        if(curr>maxi){
            maxi=curr;
        }
        if(curr<0){
            curr=0;
        }
    }
    cout<<maxi;
}