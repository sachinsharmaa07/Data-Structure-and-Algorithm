#include<iostream>
using namespace std;
bool isSorted(int arr[],int n){
    if(n==0 || n==1){
        return true;
    }
    return (arr[n]>=arr[n-1] && isSorted(arr,n-1));
}
int main(){
    int arr[]={1,2,3,4,99,100};
    int n=6;
    cout<<isSorted(arr,n);
    return 0;
}