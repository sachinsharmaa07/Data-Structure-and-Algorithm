#include<iostream>
using namespace std;
bool isSafe(vector<vector<char>>& board,int row,int col,char dig){
        //vertically
        for(int i=0;i<9;i++){
            if(board[row][i]==dig){
                return false;
            }
        }
        for(int j=0;j<9;j++){
            if(board[j][col]==dig){
                return false;
            }
        }
        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int m=sr;m<=sr+2;m++){
            for(int n=sc;n<=sc+2;n++){
                if(board[m][n]==dig){
                    return false;
                }
            }
        }
        return true;
    }
bool helper(vector<vector<char>>& board ,int row ,int col){
        if(row==9){
            return true;
        }
        int nextRow=row;int nextCol=col+1;
        if(nextCol==9){
            nextRow=row+1;
            nextCol=0;
        }
        if(board[row][col]!='.'){
            return helper(board,nextRow,nextCol);

        }
        for(char i='1';i<='9';i++){
            if(isSafe(board,row,col,i)){
                board[row][col]=i;
                 if(helper(board,nextRow,nextCol))return true;
                 board[row][col]='.';

            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        helper(board,0,0);
    }
    int main(){
        
        vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solveSudoku(board);

    cout << "Solved Sudoku:\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    }