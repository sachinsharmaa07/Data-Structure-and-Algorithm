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
        l[v].push_back(u);//not written in case of directed graph
    }
    void printGraph(){
        for(int i=0;i<v;i++){
            cout<<" : ";
            for(int j : l[i]){
                cout<<j<<" ";
            }
        cout<<"\n";
        }
    }
    bool isCycleUndDFS(int src ,int parent , vector<bool>& vis){
        vis[src]=true;
        for(int v: l[src]){
            if(!vis[v]){
                if(isCycleUndDFS(v,src,vis)){
                    return true;
                }
            }
            else if(parent!=v){
              return true;
            }
        }
        return false;

    }
    bool isCycle(){
        vector<bool>vis(v,false);
        for(int i=0;i<v;i++){
            if(!vis[i]){
                if(isCycleUndDFS(i,-1,vis)){
                    return true;
                }
            }
        }
        return false;

    }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.printGraph();
    cout << "Cycle: " << (g.isCycle() ? "Yes" : "No") << endl;
    return(0);
}