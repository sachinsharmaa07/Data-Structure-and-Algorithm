#include<iostream>
#include<vector>
using namespace std;
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis,int n , int m){
        if(i>=n || j>=m || i<0 || j<0 || grid[i][j] !='1' || vis[i][j]){
            return;
        }
        vis[i][j]=true;
        dfs(i-1,j,grid,vis,n,m);
        dfs(i+1,j,grid,vis,n,m);
        dfs(i,j-1,grid,vis,n,m);
        dfs(i,j+1,grid,vis,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int island=0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,grid,vis,n,m);
                    island++;
                }
            }
        }
        return island;
    }
    int main(){
        vector<vector<char>> grid={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
        cout<<numIslands(grid);
    }   