#include<iostream>
using namespace std;
bool isValid(vector<vector<int>> &grid,int r,int c,int expected){
    if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || grid[r][c]!=expected){
        return false;
    }
    if(expected==grid.size()*grid[0].size()-1){
        return true;
    }
    return isValid(grid,r+2,c+1,expected+1) || isValid(grid,r+1,c+2,expected+1) ||
           isValid(grid,r-1,c+2,expected+1) || isValid(grid,r-2,c+1,expected+1) ||
           isValid(grid,r-2,c-1,expected+1) || isValid(grid,r-1,c-2,expected+1) ||
           isValid(grid,r+1,c-2,expected+1) || isValid(grid,r+2,c-1,expected+1);
}
bool checkValidGrid(vector<vector<int>> &grid){
    return isValid(grid,0,0,0);
}
int main(){
    vector<vector<int>> grid={{0,59,38,33,30,17,8,63},
                              {37,34,31,60,9,62,29,16},
                              {58,1,36,39,32,27,18,7},
                              {35,48,41,26,61,10,15,28},
                              {42,57,2,49,40,23,6,19},
                              {47,50,45,54,25,20,11,14},
                              {56,43,52,3,22,13,24,5},
                              {51,46,55,44,53,4,12,21}};
    cout<<checkValidGrid(grid);

}