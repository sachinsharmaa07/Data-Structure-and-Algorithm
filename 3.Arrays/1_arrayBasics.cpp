#include<iostream>
using namespace std;
void rev(int arr[],int size){
    int start =0;
    int end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;end--;
    }
}
// reverse an array using 2 pointer approach
int main(){
    int size=5;
    int arr[5]={1,2,3,4,5};
    rev(arr,size);
    for(int i=0;i<size;i++){
        cout<<i<<"th element is "<<arr[i]<<endl;
    }


}