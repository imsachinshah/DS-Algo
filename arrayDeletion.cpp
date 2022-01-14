#include <iostream>
using namespace std;

void arrPrint(int arr[], int size){
    // Code for Transveral

    for(int i = 0; i<size; i++){
        cout<< arr[i] << ", ";
    }
    cout << "\n";
}

int deleteArr(int arr[], int size, int capacity, int element){
    // Code For Deletion
    int index = -1;

    for(int i = 0; i<size; i++){
        if( element == arr[i]){
            index = i;
            break;
        }
    }

    for(int i = index; i < size; i++){
        arr[i] = arr[i+1];
    }
    
    return 1;
}


int main(){

    int arr[100] = {2, 6, 10, 20, 30};
    int size = 5, element = 20;
    
    arrPrint(arr, 5);
    // insertArr(arr, size, 100, element, index);

    deleteArr(arr, size, 100, element);

    size -= 1;
    arrPrint(arr, size);

    return 0;
}