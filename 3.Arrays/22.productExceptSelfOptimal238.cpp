#include<iostream>
#include<vector>
using namespace std;
vector <int>pdEi(vector<int> vec){
    int x=vec.size();
    vector<int> ans(x,1);
   //vector<int> prefix(x,1);
   //vector<int> suffix(x,1);
    int prefix=1;
    for(int i=1;i<x;i++){
        //prefix[i]=prefix[i-1]*vec[i-1];
        ans[i]=ans[i-1]*vec[i-1];

    }
    int suffix=1;
    for(int i=x-2;i>=0;i--){
        suffix*=vec[i+1];
        ans[i]*=suffix;


    }
    return ans;
}
int main(){
    vector<int> vec={1,2,3,4};
    vector <int>res=pdEi(vec);
    for(int i : res){
        cout<<i<<" ";
    }

}