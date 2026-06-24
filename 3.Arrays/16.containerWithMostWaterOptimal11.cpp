#include<iostream>
#include<vector>
using namespace std;
int findMax(vector <int> vec){
    int x=vec.size();
    int capacity=0;
    int lp=0;
    int rp=x-1;
    while(rp>lp){
        int hei=min(vec[lp],vec[rp]);
        int cap=(rp-lp)*hei;
        capacity=max(capacity,cap);
        if(vec[rp]>vec[lp]){
            lp++;
        }
        else{
            rp--;
        }

    }
    return capacity;

}
int main(){
    vector <int> vec={1,4,5,3,2,24,6,6,47,33,32,33};
    int x=findMax(vec);
    cout<<"Max Capacity: "<<x;

}