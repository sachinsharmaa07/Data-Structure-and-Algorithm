#include<iostream>
using namespace std; 
bool isPallin(string s){
        string x=s;
        reverse(x.begin(),x.end());
        if(x==s){
            return true;
        }
        return false;

    }
    void helper(string s,vector<vector<string>> &ans,vector<string>&part ){
        if(s.size()==0){
            ans.push_back(part);
            return;
        }
        for(int i=0;i<s.size();i++){
            string abc=s.substr(0,i+1);
            if(isPallin(abc)){
                part.push_back(abc);
                helper(s.substr(i+1),ans,part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        helper(s,ans,part);
        return ans;

        
    }
int main(){
    string s="aab";
    vector<vector<string>> result=partition(s);
    for(auto vec: result){
        for(auto str: vec){
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;  
}