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
        queue<int>q;
        vector<bool>vis(v,false);
        q.push(0);
        vis[0]=true;
        while(q.size()>0){
            int u=q.front();
            cout<<u<<" ";
            q.pop();
            for(int v:l[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    void dfsTraversal(int u,vector<bool>&visited){
       visited[u]=true;
       cout<<u<<" ";
       for(int v:l[u]) {
        if(!visited[v]){
            dfsTraversal(v,visited);
        }
       }
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    


    g.printGraph();
    g.bfsTraversal();
    vector<bool>visited(4,false);
    cout<<endl;
    g.dfsTraversal(0,visited);


}