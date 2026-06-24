#include<iostream>
using namespace std;
int main(){
    int maxsum=INT_MIN;
    int currsum=0;
    int arr[5]={2,4,-3,4,24};
    for(int i=0;i<5;i++){
        currsum+=arr[i];
        maxsum=max(maxsum,currsum);
        if(currsum<=0){
            currsum=0;
        }
        
    }
cout<<"Maximum sum of Subarray is : "<<maxsum;
}