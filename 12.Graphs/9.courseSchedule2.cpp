#include<iostream>
#include<vector>
using namespace std;
  void topo(int src, vector<vector<int>>& e,vector<bool>&vis,stack<int>&st){
        vis[src]=true;
        for(int i=0;i<e.size();i++){
            int u=e[i][1];
            int v=e[i][0];
            if(u==src){
                if(!vis[v]){
                    topo(v,e,vis,st);
                }
            }
    }
    st.push(src);
    }
    bool isCycle(int src, vector<vector<int>>& e,vector<bool>&vis,vector<bool>&recPath){
        vis[src]=true;
        recPath[src]=true;
        for(int i=0;i<e.size();i++){
            int u=e[i][1];
            int v=e[i][0];
            if(u==src){
                if(!vis[v]){
                    if(isCycle(v,e,vis,recPath)){
                        return true;
                    }
                }
                else if(recPath[v]){
                    return true;
                }
            }
        }
        recPath[src]=false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& e) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,e,vis,recPath)){
                    return {};
                }
            }
        }
        vector<int> ans;
        vis.assign(n,false);
         for(int i=0;i<n;i++){
            if(!vis[i]){
                topo(i,e,vis,st);
            }
        }
        while(st.size()>0){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
int main(){
    int n=8;
    vector<vector<int>>e={{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    vector<int>ans=findOrder(n,e);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }   
}  