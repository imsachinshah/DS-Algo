#include <iostream>
using namespace std;

void arrPrint(int arr[], int size){
    // Code for Transveral

    for(int i = 0; i<size; i++){
        cout<< arr[i] << ", ";
    }
    cout << "\n";
}

int insertArr(int arr[], int size, int capacity, int element, int index){
    // Code For Insertion
    
    if( size == capacity){
        return -1;
    }

    for(int i = size; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int sortedInsertArr(int arr[], int size, int capacity, int element){

    // Code For Insertion in Sorted Array 
    
    int index = -1;
    
    if( size == capacity){
        return -1;
    }

    for( int j = 0; j <= size; j++){
        if(element > arr[j]){
            index++;
        }
    }

    for(int i = size; i >= index; i--){
        arr[i+1] = arr[i];
    }
    arr[index] = element;
    return 1;
}

int main(){

    int arr[100] = {2, 6, 10, 20, 30};
    int size = 5, element = 22, index = 3;
    
    arrPrint(arr, 5);
    // insertArr(arr, size, 100, element, index);

    sortedInsertArr(arr, size, 100, element);

    size += 1;
    arrPrint(arr, size);

    return 0;
}