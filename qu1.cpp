#include <iostream>
using namespace std;

void arrPrint(int arr[], int size){
    // Code for Transveral

    for(int i = 0; i<size; i++){
        cout<< arr[i] << ", ";
    }
    cout << "\n";
}

void rotate(int arr[], int n){

    int p = arr[0];

    for(int i = 1; i < n; i++){
        int temp = arr[i];
        arr[i] = p;
        p = temp;
    }

    arr[0] = p;
}



int main(){

    int arr[] = {2, 6, 10, 20, 30};
    int size = 5;
    
    arrPrint(arr, 5);
    // insertArr(arr, size, 100, element, index);

    rotate(arr, size);

    size += 1;
    arrPrint(arr, size);

    return 0;
}