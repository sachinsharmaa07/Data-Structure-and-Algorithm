#include<iostream>
using namespace std;
int part(vector<int> &arr,int st ,int end){
    int idx=st-1;
    int pivt=arr[end];
    for(int j=st;j<end;j++){
        if(arr[j]<=pivt){
            idx++;
            swap(arr[j],arr[idx]);
        }
    }
    idx++;
    swap(arr[idx],arr[end]);
    return idx;
}
void quickSort(vector<int> &arr,int st ,int end){
    if(st<end){
    int piv=part(arr, st ,end);
    quickSort(arr,st,piv-1);
    quickSort(arr,piv+1,end);
    }
}


int main(){
    vector<int> arr={2,23,2,2,5,4,3,3,234,6,23456,1254,6,2356,346,134};
    quickSort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
    }
}