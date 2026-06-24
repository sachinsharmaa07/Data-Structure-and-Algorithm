#include<iostream>
using namespace std;
   vector<int> bfs(vector<vector<int>> &adj) {
        queue<int> q;
        q.push(0);
        vector<int> ans;
        vector<bool>vis(adj.size(),false);
        vis[0]=true;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v: adj[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return ans;
        
    }
int main(){
    vector<vector<int>> adj={{1,2},{0,3},{0,3},{1,2}};
    vector<int> ans=bfs(adj);
    for(int i:ans){ 
        cout<<i<<" ";
    }
    return 0;
}