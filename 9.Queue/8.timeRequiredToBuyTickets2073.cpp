#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int timeRequiredToBuyBF(vector<int>& t, int k) {
        queue<int>q;
        int ans=0;
        for(int i=0;i<t.size();i++){
            q.push(i);
        }
        while(!q.empty()){
            ans++;
            int idx=q.front();
            q.pop();
            t[idx]--;
            if(t[idx]==0 && idx==k){
                return ans;
            }
            if(t[idx]!=0){
                q.push(idx);
            }
        }
        return ans;
    }
int main(){
   
    return 0;
}