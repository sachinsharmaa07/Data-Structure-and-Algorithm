class Solution {
  public:
  void dfshelper(vector<vector<int>>& adj, vector<int> &ans, int src,vector<bool> &vis){
      vis[src]=true;
      for(int v:adj[src]){
          if(!vis[v]){
              dfshelper(adj,ans,v,vis);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> ans;
        vector<bool> vis(adj.size(),false);
        dfshelper(adj,ans,0,vis);
        return ans;
        
    }
};

//dfs code 

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> ans;
        vector<bool>vis(adj.size(),false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(int v:adj[u]){
                if(!vis[v]){
                q.push(v);
                vis[v]=true;   
                }
            }
        }
        return ans;
        
    }
}; //BFS code


// component connected graph 
class Solution {
  public:
  void dfs(vector<vector<int>>&adj,vector<bool>&vis,int src,vector<int>&temp){
      vis[src]=true;
      temp.push_back(src);
      for(int v:adj[src]){
          if(!vis[v]){
              dfs(adj,vis,v,temp);
          }
      }
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
       vector<vector<int>>adj(V);
       vector<vector<int>>ans;
       for(auto it : edges){
           int u=it[0];
           int v=it[1];
           adj[u].push_back(v);
           adj[v].push_back(u);
       }
       vector<bool> vis(adj.size(),false);
       for(int i=0;i<vis.size();i++){
           if(!vis[i]){
               vector<int>temp;
               dfs(adj,vis,i,temp);
               ans.push_back(temp);
           }
       }
       return ans;
    }
};
//cycle detection in undirected graph
class Solution {
  public:
  bool dfs( vector<vector<int>>&adj,vector<bool>&vis,int src,int parent){
      vis[src]=true;
      for(int v :adj[src]){
          if(!vis[v]){
              if(dfs(adj,vis,v,src)){
                  return true;
              }
          }
          else{
              if(v!=parent){
                  return true;
              }
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
      vector<vector<int>>adj(V);
      for(auto it:edges){
          int u=it[0];
          int v=it[1];
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      vector<bool>vis(V,false);
      for(int i=0;i<V;i++){
          if(!vis[i]){
              if(dfs(adj,vis,i,-1)){
                  return true;
              }
          }
      }
      return false;
    }
};



/// rotten oranges
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            if(i+1<n && !vis[i+1][j] && grid[i+1][j]==1){
                q.push({{i+1,j},time+1});
                vis[i+1][j]=true; grid[i+1][j]=2;
                
            }
            if(j+1<m && !vis[i][j+1] && grid[i][j+1]==1){
                q.push({{i,j+1},time+1});
                vis[i][j+1]=true;
                grid[i][j+1]=2;
            }
            if(i-1>=0 && !vis[i-1][j] && grid[i-1][j]==1){
                q.push({{i-1,j},time+1});
                vis[i-1][j]=true;
                 grid[i-1][j]=2;
            }
            if(j-1>=0 && !vis[i][j-1] && grid[i][j-1]==1){
                q.push({{i,j-1},time+1});
                vis[i][j-1]=true;
                grid[i][j-1]=2;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};



/// cycle detection in directed graph
class Solution {
  public:
  bool dfs(vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&rec,
  int src){
      vis[src]=true;
      rec[src]=true;
      for(int v:adj[src]){
          if(!vis[v]){
             if(dfs(adj,vis,rec,v)){
                 return true;
             }
          }
          else if(rec[v]){
              return true;
          }
      }
      rec[src]=false;
      return false;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
       vector<vector<int>>adj(V);
       for(auto it: edges){
         int u= it[0];
         int v=it[1];
         adj[u].push_back(v);
       }
       vector<bool>vis(V,false);
       vector<bool>rec(V,false);
       for(int i=0;i<V;i++){
          if(!vis[i]){
              if(dfs(adj,vis,rec,i)){
                  return true;
              }
          }
       }
       return false;
        
    }
};

