#include<iostream>
using namespace std;

bool isCycle(int src, vector<vector<int>>& e,vector<bool>&vis,vector<bool>&recPath){
        vis[src]=true;
        recPath[src]=true;
        for(int i=0;i<e.size();i++){
            int u=e[i][0];
            int v=e[i][1];
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
    bool canFinish(int n, vector<vector<int>>& e) {
        vector<bool>vis(n,false);
        vector<bool>recPath(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,e,vis,recPath)){
                    return false;
                }
            }
        }
        return true;
    
    }
int main(){
    int n=8;
    vector<vector<int>>e={{0,1},{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}};
    cout<<canFinish(n,e);
     
}