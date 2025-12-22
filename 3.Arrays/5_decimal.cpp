#include<iostream>
using namespace std;
void conversion(int x){
    int pow=1;
    int res=0;
while(x>0){
    int rem=x%2;
    x=x/2;
    res+=pow*rem;
    pow*=2;
}


}
int main(){
    int x=101010;
    conversion(x);
    
}