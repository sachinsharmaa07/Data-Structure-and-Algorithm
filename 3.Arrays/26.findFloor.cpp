#include<iostream>
#include<vector>
using namespace std;
 int findFloor(vector<int>& arr, int x) {
        // code here
        int st=0;int end=arr.size()-1;
        int ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]<=x){
                ans=mid;
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return ans;
    }
int main(){
    vector <int> vec={1,2,8,10,10,12,19};
    int x=vec.size();
    int res=findFloor(vec,9);
    cout<<res<<" is the index of floor element";  
}  