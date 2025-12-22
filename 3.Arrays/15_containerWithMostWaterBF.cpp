#include<iostream>
#include<vector>
using namespace std;
int findMax(vector <int> vec){
    int x=vec.size();
    int capacity=0;
    for(int i=0;i<x;i++){
        for(int j=i+1;j<x;j++){
            int width=j-i;
            int height=min(vec[i],vec[j]);
            int cap=width*height;
            capacity=max(capacity,cap);
        }
    }
    return capacity;

}
int main(){
    vector <int> vec={1,4,5,3,2,24,6,6,47,33,32,33};
    int x=findMax(vec);
    cout<<"Max Capacity: "<<x;

}