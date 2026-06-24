#include<iostream>
using namespace std;

void dfsHelper(vector<vector<int>>& adj,vector<bool>&vis,int root,vector<int>&ans){
        vis[root]=true;
        ans.push_back(root);
        for(int v:adj[root]){
            if(!vis[v]){
                dfsHelper(adj,vis,v,ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<bool>vis(adj.size(),false);
        vector<int> ans;
        dfsHelper(adj,vis,0,ans);
        return ans;
    }
int main(){
    vector<vector<int>> adj={{1,2},{0,3},{0,3},{1,2}};
    vector<int> ans=dfs(adj);
    for(int i:ans){
        cout<<i<<" ";
    }
    return 0;

}  