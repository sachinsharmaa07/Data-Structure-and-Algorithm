#include<iostream>
#include<vector>
using namespace std;
int BsN(vector <int> &vec,int tar,int st,int end){
    if(st>end){
        return -1;
    }
    int mid=st+(end-st)/2;
    if(vec[mid]==tar){
        return mid;
    }
    else if(vec[mid]>tar){
       return BsN(vec,tar,st,mid-1);
    }
    else{
       return BsN(vec,tar,mid+1,end);
    }

}
int main(){
    vector <int> vec={1,2,3,4,5,6,7,8,9};
    int x=vec.size();
    int res=BsN(vec,3,0,x-1);
    cout<<res<<" is the index of searched element";
}