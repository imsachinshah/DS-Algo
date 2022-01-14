#include <iostream>
using namespace std;

void arrPrint(int arr[], int size){
    // Code for Transveral

    for(int i = 0; i<size; i++){
        cout<< arr[i] << ", ";
    }
    cout << "\n";
}

int linearSearchArr(int arr[], int size, int capacity, int element){
    
    // Code For Linear Search
    int flag = 0;
    int index = -1;

    for(int i = 0; i < size; i++){
        if(arr[i] == element){
            flag = 1;
            index = i;
            break;
        }
    }

    if (flag == 1){
        cout << "Element Found at position "<< index << endl;
        return 1;
    }
    else{
        return 0;
    }
}

int binarySearchArr(int arr[], int size, int capacity, int element){

    // Code For Binary Search
    int low = 0, high = size - 1;

    int mid;
    int n = size - 1;
    int flag = -1;
    int index = -1;
    while(n != -1 ){

        mid = ( low + high) / 2;

        if( arr[mid] == element){
            cout << "Elelemet Found at "<< mid << " index." << endl;
            flag = 0;
            index = mid;
            return 0;
        }
        else if(arr[mid] < element){
            low = mid;
            
        }
        else{
            high = mid;
        }
        n--;
    }
    return 1;
}

int main(){

    int arr[100] = {2, 6, 10, 20, 30};
    int size = 5, element = 6, index = 3;
    
    arrPrint(arr, 5);
    // insertArr(arr, size, 100, element, index);

    binarySearchArr(arr, size, 100, element);

    size += 1;
    arrPrint(arr, size);

    return 0;
}