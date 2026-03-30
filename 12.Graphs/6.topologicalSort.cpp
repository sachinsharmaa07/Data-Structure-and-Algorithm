#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include <stack>
using namespace std;
class Graph{
    int v;
    list<int> * l;
    public:
    Graph(int v){
        this->v=v;
        l=new list<int>[v];
    }
    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    void topoSort(int u,vector<bool>&visited,stack<int>&st){
       visited[u]=true;
       for(int v:l[u]) {
        if(!visited[v]){
            topoSort(v,visited,st);
        }
       }
        st.push(u);
    }
    void sort(){
        vector<bool>vis(v,false);
        stack<int>st;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                topoSort(i,vis,st);
            }
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
    }
   
};
int main(){
    Graph g(6);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(3,5);
    g.addEdge(4,5);
    g.sort();
    



}