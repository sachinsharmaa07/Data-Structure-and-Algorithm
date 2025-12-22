#include<iostream>
using namespace std;
void bubbleSort(int arr[],int x){
    for(int i=0;i<x-1;i++){
        bool isSorted=false;
        for(int j=0;j<x-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSorted=true;//if swap is done
            }
//to track if swap not done that is already sorted
//skip other iteration
        }
        if(!isSorted){
            return;//already sorted 
        }

    }
    

}
void selectSort(int arr[],int x){
    for(int i=0;i<x-1;i++){//selection sort 
        int smallestIndex=i;
        for(int j=i+1;j<x;j++){
            if(arr[j]<arr[smallestIndex]){
                smallestIndex=j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];      // element to insert
        int j = i - 1;         // last index of the sorted left part

        // Shift elements of the sorted part that are greater than key
        // to one position ahead to make space for key.
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Place key at its correct position
        arr[j + 1] = key;
    }
}

void printArr(int arr[],int x){
    for(int i=0;i<x;i++){
        cout<<arr[i]<<" ";
    }

}
int main(){
    int arr[]={23,4,53,455,34,246,24,34,33,21};
    int size=sizeof(arr)/sizeof(arr[0]);
    selectSort(arr,size);
    printArr(arr,size);

}