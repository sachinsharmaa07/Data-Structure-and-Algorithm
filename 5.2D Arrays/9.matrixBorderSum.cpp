#include<iostream>
#include<vector>
using namespace std;

int matrixBorderSum(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || j==0 || j==m-1 || i==n-1){
                sum+=grid[i][j];
            }
        }
    }
    return sum;
}
int main(){
    vector<vector<int>> grid={{1,2,3},{4,5,6},{7,8,9}};
    cout<<matrixBorderSum(grid);
}