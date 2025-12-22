#include<iostream>
using namespace std;
void merge(vector<int> &arr,int st,int mid,int end){
    vector<int>temp;
    int i=st;int j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
        temp.push_back(arr[j]);j++;

        }
    }
    while(i<=mid){
        temp.push_back(arr[i]);
            i++;
    }
    while(j<=end){
        temp.push_back(arr[j]);j++;
    }
    
    for(int k=0;k<temp.size();k++){
        arr[k+st]=temp[k];
    }
}
void mergeSort(vector<int> &arr,int st,int end){
    if(st>=end){
        return;
    }
    int mid=st+(end-st)/2;
    mergeSort(arr,st,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,st,mid,end);
   
}
int main(){
    vector<int> arr={1,64,3634,33,556,34,1,2,4,5,2,2,5,54,534545,534242,3};
    mergeSort(arr,0,arr.size()-1);
    for(int i:arr){
        cout<<i<<" ";
    }
}