#include <iostream>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        int sr=0,sc=0,er=m-1,ec=n-1;
        vector<int>ans;
        while(sr<=er && sc<=ec){
            //top
            for(int j=sc;j<=ec;j++){
                ans.push_back(matrix[sr][j]);
            }
            //right
            for(int j=sr+1;j<=er;j++){
                ans.push_back(matrix[j][ec]);
                
            }            //bottom
            for(int i=ec-1;i>=sc;i--){
                if(sr==er){
                    break;
                }
                ans.push_back(matrix[er][i]);
                
            }            //left
            for(int i=er-1;i>=sr+1;i--){
                if(sc==ec){
                    break;
                }
                ans.push_back(matrix[i][sc]);
                
            }
            sc++;sr++;er--;ec--;
        }
        return ans;
    }
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };  
    vector<int> result = spiralOrder(matrix);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
} 