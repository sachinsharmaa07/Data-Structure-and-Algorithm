#include<iostream>
using namespace std;
int SingleSort(vector <int> &arr){
    int x=arr.size();
    if(x==1)return arr[0];
    int st=0;int end=x-1;
    while(st<=end){
    int mid=st+(end-st)/2;
    if(mid==0 && arr[0]!=arr[1])return arr[mid];
    if(mid==x-1 && arr[x-1]!=arr[x-2])return arr[mid];
    if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]){
        return arr[mid];
    }
    if(mid%2==0){
        if(arr[mid-1]==arr[mid]){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    else{
    if(arr[mid-1]==arr[mid]){
        st=mid+1;
    }
    else{
        end=mid-1;
        }
    }


    }
    return -1;
}
int main(){
    vector<int>arr={1,1,2,2,4,4,5,6,6};
    int res=SingleSort(arr);
    cout<<"only single element in sorted arrray is ==> "<<res;
}