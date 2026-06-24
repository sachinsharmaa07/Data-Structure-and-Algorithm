#include<iostream>
using namespace std;
 int maxProfit(vector<int>& prices) {
        int maxp=0;int bestb=prices[0];
        int l=prices.size();
        for(int i =1;i<l;i++){
            if(prices[i]>bestb){
           maxp=max(maxp,prices[i]-bestb);
            }
            bestb=min(bestb,prices[i]);
        }
        return maxp;
    }
int main(){
    vector<int>vec={1,2,3,531,34,13,31,293,12323,232,22323};
    int maxprofit=maxProfit(vec);
    cout<<"Max profit from the vector is : "<<maxprofit;
}