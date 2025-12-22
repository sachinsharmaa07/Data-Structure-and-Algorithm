#include<iostream>
using namespace std;
bool isValid(vector<int>&vec,int n,int m ,int max){
    int student=1;int pages=0;
    for(int i=0;i<n;i++){
        if(vec[i]>max){
            return false;
        }
        if(pages+vec[i]<=max){
            pages+=vec[i];
            
        }
        else{
            student++;
            pages=vec[i];
            
        }


    }
    if(student>m){
        return false;
    }
    else{
        return true;
    }
}
int allocateBook(vector<int> &vec,int n,int m){
    int sum=0;
    if(m>n){
        return -1;
    }
    for(int i=0;i<n;i++){
        sum+=vec[i];
    }
    int ans=-1;
    int st=0;int end=sum;
    while(st<=end){
       int mid=st+(end-st)/2;
       if(isValid(vec,n,m,mid)){
        ans=mid;
        end=mid-1;

       }
       else{
        st=mid+1;
       }

    }
    return ans;


}
int main(){
    vector<int> vec ={15,17,20};
    int n=4;int m=2;
    cout<<allocateBook(vec,n,m);

}