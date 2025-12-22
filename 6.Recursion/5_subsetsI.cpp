#include<iostream>
using namespace std;
void printSubsets(vector<int> &arr, vector<int> &ans,int index){
    if(index==arr.size()){
        for(int num : ans){
            cout<<num<<" ";

        }
        cout<<endl;
        return;

    }
    ans.push_back(arr[index]);
    printSubsets(arr,ans,index+1);
    ans.pop_back();
    printSubsets(arr,ans,index+1);


}
int main(){
    vector <int> arr={1,2,3};
    vector<int>ans;
    int index=0;
    printSubsets(arr,ans,index);

}