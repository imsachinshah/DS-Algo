
#include <iostream>

int recursionSum(int a[], int size){
    
   
    
    if(size == 1)
        return a[0];
    
    int sum = a[0] + recursionSum(a+1, size-1); 
        
}

bool recursionLinearSearch(int a[], int size, int key){
    if (size == 1 && a[0] == key)
        return 1;
    else
        return 0;
    
    bool ans = recursionLinearSearch(a+1, size-1, key);
    
    return ans == 1 ? 1 : 0;
        
    
}

bool recursionBinarySearch(int arr[], int s, int e, int key){
    int mid = s + (e -s)/2;
    
    if (s>e)
        return 0;
    
    if( arr[mid] == key)
        return 1;
        
    if ( arr[mid] < key)
        return recursionBinarySearch(arr, mid + 1, e, key);
    else
        return recursionBinarySearch(arr, s, mid -1, key);
   
}

int main() {
    // Write C++ code here
    int arr[] = {2, 3, 4, 6, 7, 7};
    // std::cout << "The sum of array: "<< recursionSum(arr, 5);
    // std::cout << "Value is found?  " << recursionLinearSearch(arr, 5, 9);
    std::cout << "Value found? " << recursionBinarySearch(arr, 0, 5, 9);
    std::cout << "Hello world!";

    return 0;
}
