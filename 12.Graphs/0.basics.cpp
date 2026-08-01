#include<iostream>
using namespace std;
int main(){
    vector<vector<int>> edges={{0,1},{1,2},{2,3},{4,2},{1,4},{0,4},{3,4}};
    int v=5;
    vector<int> indegree(v,0);
    vector<int> outdregree(v,0);
    for(auto edge:edges){
        indegree[edge[1]]++;
        outdregree[edge[0]]++;
    }
    cout<<"Indegree of each vertex is: ";
    for(int i=0;i<v;i++){
        cout<<indegree[i]<<" ";
      
    }
    cout<<endl;
    cout<<"Outdegree of each vertex is: ";
    for(int i=0;i<v;i++){
        cout<<outdregree[i]<<" ";
        
    }
    cout<<endl;
    cout<<"Total degree of each vertex is: ";
    for(int i=0;i<v;i++){
        cout<<indegree[i]+outdregree[i]<<" ";
        
    }
    cout<<endl;

}