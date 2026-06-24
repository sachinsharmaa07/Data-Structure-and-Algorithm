#include<iostream>
#include<vector>
using namespace std;
    int solve(int m,int n ,int i ,int j,string path,vector<string>&allpath){
        if(i==m-1 && j ==n-1){
            allpath.push_back(path);
            return 1;
        }
        if(i>=m || j >=n){
            
            return 0;
        }
        return solve(m,n , i+1,j,path+"->D",allpath)+ solve(m,n,i,j+1,path+"->R",allpath);
    }
    int main() {
        vector<string>allpath;
        string path="";
        int x= solve(3,4,0,0,path,allpath);
        for (string p : allpath) {
        cout << p << endl;
    }
    }