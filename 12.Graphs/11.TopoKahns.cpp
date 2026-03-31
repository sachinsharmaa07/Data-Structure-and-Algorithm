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
       //not written in case of directed graph
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
    vector<int> Kahns(){
        vector<int> res;
        queue<int>q;
        vector<int> indeg(v,0);
        for(int u=0;u<v;u++){
            for(int V:l[u]){
                indeg[V]++;
            }
        }
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(q.size()>0){
            int curr=q.front();q.pop();
            res.push_back(curr);
            for(int v:l[curr]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return res;
    }
    
    
    
};
int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    vector<int> result = g.Kahns();
    for(int node : result){
        cout<<node<<" ";
    }  


}