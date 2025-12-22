#include<iostream>
using namespace std;
int main(){
    int decimal=42;int dec=decimal;
    int ans=0; int pow=1;
    while(decimal>0){
        int rem=decimal%2;
        decimal=decimal/2;
        ans+=rem*pow;
        pow*=10;
    }
    cout<<"Decimal to Binary of "<<dec<<" is "<<ans;
}