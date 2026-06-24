#include<iostream>
using namespace std;
 bool searchinrow(vector<vector<int>>& matrix, int target,int row)
    {
        int n=matrix[0].size();
        int st=0,end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]>target){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }return false;

    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size(),n=matrix[0].size();
        int startrow=0,endrow=m-1;
        while(startrow<=endrow){
            int midrow=startrow+(endrow-startrow)/2;
            if(target>=matrix[midrow][0] && target<=matrix[midrow][n-1])
            {
               return searchinrow(matrix,target,midrow);
                
            }
            else if(target>matrix[midrow][n-1]){
                startrow=midrow+1;
            }
            else{
                endrow=midrow-1;
            }
        }return false;
    }
int main(){
    vector<vector<int>> matrix={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    cout<<searchMatrix(matrix,target);
    return 0;
}