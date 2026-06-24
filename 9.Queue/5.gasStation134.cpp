#include<iostream>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tc=0;
        int tg=0;
        for(int i=0;i<gas.size();i++){
            tc+=cost[i];
            tg+=gas[i];
        }
        if(tc>tg){
            return -1;
        }
        int currG=0;int start=0;
        for(int i=0;i<gas.size();i++){
            currG+=gas[i]-cost[i];
            if(currG<0){
                start=i+1;
                currG=0;
            }
        }
        return start;
        
    }
    int main(){
        vector<int>gas={1,2,3,4,5};
        vector<int>cost={3,4,5,1,2};
        int startIndex=canCompleteCircuit(gas,cost);
        if(startIndex!=-1){
            cout<<"Start index to complete the circuit: "<<startIndex<<endl;
        }
        else{
            cout<<"Not possible to complete the circuit"<<endl;
        }
        return 0;
    }