#include<iostream>
using namespace std;
#include<vector>
#include<stack>
vector<int> NextGreater(vector<int> vec){
    stack<int>s;
    vector<int> ans[vec.size()];
    for(int i=vec.size()-1;i>=0;i--){
        while(s.size()>0 && s.top()<=vec[i]){
            s.pop();
        }
        if(s.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=s.top();
        }
        s.push(vec[i]);
        }
        return ans;
}
int main(){
    vector<int> vec={2,1,5,3,4};
    vector<int> result=NextGreater(vec);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}   