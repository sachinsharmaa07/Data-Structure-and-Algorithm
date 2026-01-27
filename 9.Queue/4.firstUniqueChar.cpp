#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;
int firstUniqChar(string s) {
        unordered_map<char,int>m;
        queue<int> q;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])==m.end()){
                q.push(i);
            }
        m[s[i]]++;
        }
        while(q.size()>0 && m[s[q.front()]]>1){
            q.pop();
        }
        if(q.size()==0){
            return -1;
        }
        else{
            return q.front();
        }
    }
    int main(){
        string s="leetcode";
        int index=firstUniqChar(s);
        if(index!=-1){
            cout<<"First unique character is at index: "<<index<<endl;
        }
        else{
            cout<<"No unique character found"<<endl;
        }
        return 0;
    }