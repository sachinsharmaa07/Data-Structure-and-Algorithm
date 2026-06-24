#include<iostream>
#include<stack>
#include<vector>
using namespace std;


vector<int> StockSpan(vector<int>Prices){
    int x=Prices.size();
    vector<int>ans(x);
    stack<int>st;
    for(int i=0;i<x;i++){
        while(st.size()>0 && Prices[st.top()]<=Prices[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i]=i+1;
        }
        else{
            ans[i]=i-st.top();
        }
        st.push(i);
    }
    return ans;
}
int main(){
    vector<int>Prices={100,80,60,70,60,75,85};
    vector<int>result=StockSpan(Prices);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}