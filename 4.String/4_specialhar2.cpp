#include<iostream>
#include<vector>
using namespace std;
    int numberOfSpecialChars(string word) {
        int x=word.size();
        vector<int>lastLow(26,-1);
        int count=0;
        vector<int>firstCap(26,-1);
        for(int i=0;i<x;i++){
            if(islower(word[i])){
                lastLow[word[i]-'a']=i;
            }
            else{
                if(firstCap[word[i]-'A']==-1){
                firstCap[word[i]-'A']=i;
                }
            }
        }
        for(int i=0;i<26;i++){
            if(firstCap[i]!=-1 && lastLow[i]!=-1 && firstCap[i]>lastLow[i]){
                count++;
            }
        }
        return count;


    }
    int main(){
        string word="abBAcC";
        cout<<numberOfSpecialChars(word);
    }   