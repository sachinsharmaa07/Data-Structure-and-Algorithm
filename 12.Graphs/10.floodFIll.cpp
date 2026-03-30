#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<vector<int>>& i, int sr, int sc, int color, int o) {
        if (sr < 0 || sc < 0 || sr >= i.size() || sc >= i[0].size()) {
            return;
        }
        if (i[sr][sc] != o) {
            return;
        }
        i[sr][sc] = color;
        dfs(i, sr + 1, sc, color, o);
        dfs(i, sr - 1, sc, color, o);
        dfs(i, sr, sc + 1, color, o);
        dfs(i, sr, sc - 1, color, o);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& i, int sr, int sc,
                                  int color) {
            if(i[sr][sc]==color){
                return i;
            }
        dfs(i, sr, sc, color, i[sr][sc]);
        return i;
    }
int main(){
    vector<vector<int>>i={{1,1,1},{1,1,0},{1,0,1}};
    int sr=1,sc=1,color=2;
    vector<vector<int>>ans=floodFill(i,sr,sc,color);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j]<<" ";
        }        cout<<endl;
    }
}   