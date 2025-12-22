 #include<iostream>
 using namespace std;
 void nqueen(vector<string> &board,int row,int n,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back({board});
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j,n)){
                board[row][j]='Q';
                nqueen(board,row+1,n,ans);
                board[row][j]='.';
            }
        }
    }

    bool isSafe(vector<string> &board,int row,int col,int n){
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q'){
                return false;
            }
        }
        for(int m=0;m<n;m++){
            if(board[m][col]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j>=0;i--,j--){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row,j=col;i>=0 && j<n;i--,j++){
            if(board[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n,string(n,'.'));
    nqueen(board,0,n,ans);
    return ans;

        
    }
int main(){
    vector<vector<string>> ans=solveNQueens(4);
}