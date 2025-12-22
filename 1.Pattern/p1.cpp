#include<iostream>
using namespace std;
int main(){
    int x=4;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<"\n";
    }cout<<"\n";cout<<"\n";
    
    for(int i=1;i<=x;i++){
        for(int j=1;j<=i;j++){
            cout<<j;
        }
        cout<<"\n";
    }cout<<"\n";cout<<"\n";
    int a=1;
    for(int i=1;i<=x;i++){
        int y=1;
        for(int j=1;j<=i;j++){
            cout<<a;
        }
        cout<<"\n";
        a++;
    }cout<<"\n";cout<<"\n";
    char A='A';
    for(int i=1;i<=x;i++){
        int y=1;
        for(int j=1;j<=i;j++){
            cout<<A;
        }
        cout<<"\n";
        A++;
    }cout<<"\n";cout<<"\n";

}