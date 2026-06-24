#include<iostream>
#include<vector>
#include<queue>
#include<list>
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
    bool isCycleUnDfs(int u,vector<bool>& vis,vector<bool>& path){
        path[u]=true;
        vis[u]=true;
        for(int v:l[u]){
            if(!vis[v]){
                if(isCycleUnDfs(v,vis,path)){
                    return true;
                }
            }
         else if(path[v]){
                    return true;
                }
        }
        path[u]=false;
        return false;
       
    }
    bool isCycle(){
        vector<bool> vis(v,false);
        vector<bool> path(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(isCycleUnDfs(i,vis,path)){
                    return true;
                }
            }
        }
        return false;
    }
    
};
int main(){
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    cout<<g.isCycle();

  
    vector<bool>visited(4,false);
 


}