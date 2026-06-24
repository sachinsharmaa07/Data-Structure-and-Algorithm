#include<iostream>
#include<vector>
#include<stack>
using namespace std;    

int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n=heights.size();
        stack<int>s;
        vector<int>r(n,0);
        vector<int>l(n,0);
        for(int i=n-1;i>=0;i--){
            while(s.size()>0 && heights[i]<=heights[s.top()]){
                s.pop();
            }
            if(s.empty()){
                r[i]=n;
            }
            else{
                r[i]=s.top();
            }
            s.push(i);
        }
        while(!s.empty()){
            s.pop();
        }
        for(int i=0;i<n;i++){
            while(s.size()>0 && heights[i]<=heights[s.top()]){
                s.pop();
            } 
            if(s.empty()){
                l[i]=-1;
            }
            else{
                l[i]=s.top();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++){
            int width=r[i]-l[i]-1;
            int currArea=heights[i]*width;
            ans=max(currArea,ans);
        }
        return ans;
    }
int main(){
    vector<int>heights={2,1,5,6,2,3};
    cout<<largestRectangleArea(heights);
}