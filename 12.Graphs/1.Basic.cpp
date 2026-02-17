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
    void bfsTraversal(){
        queue<int> q;
        q.push(0);
        vector<int>visited(v,false);
        visited[0]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            cout<<u<<" ";
            for(int v: l[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
    }
    void dfsTraversal(int u,vector<bool>&visited){
        cout<<u<<" ";
        visited[u]=true;
        for(int v:l[u]){
            if(!visited[v]){
                dfsTraversal(v,visited);
            }
        }
        }
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(3,1);

    g.printGraph();
    g.bfsTraversal();
    vector<bool>visited(4,false);
    cout<<endl;
    g.dfsTraversal(0,visited);


}