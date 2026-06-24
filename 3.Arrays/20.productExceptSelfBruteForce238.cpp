#include<iostream>
#include<vector>
using namespace std;
vector <int>pdEi(vector<int> vec){
    int x= vec.size();
    vector <int>res;
    for(int i=0;i<x;i++){
        int product=1;
        for(int j=0;j<x;j++){
            if(j==i){

                continue;
            }
            product*=vec[j];

        }
        res.push_back(product);
    }
    return res;
}
int main(){
    vector<int> vec={1,2,3,4};
    vector <int>res=pdEi(vec);
    for(int i : res){
        cout<<i<<" ";
    }

}