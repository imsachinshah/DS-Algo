#include <iostream>
using namespace std;

void printArray(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n";
}

void selectionSort(int A[], int n){
    int indexOfMin, temp;
    cout << "Selection Sort is running... \n";

    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if(A[indexOfMin] > A[j]){
                indexOfMin = j;
            }
        }

        temp = A[i];
        A[i] = A[indexOfMin];
        A[indexOfMin] = temp;
        
    }
    
    
}

int main()
{
   
    // 00 01 02 03 04 05
    // 02 65 20 12 00 37

    // After First Pass 
    // 00 01 02 03 04 05
    // 00 65 20 12 02 37

    // After Second Pass 
    // 00 01 02 03 04 05
    // 00 02 20 12 65 37

    // After Third Pass 
    // 00 01 02 03 04 05
    // 00 02 12 20 65 37

    // After Fourth Pass 
    // 00 01 02 03 04 05
    // 00 02 12 20 65 37

    // After Fifth Pass 
    // 00 01 02 03 04 05
    // 00 02 12 20 37 65


    int a[] = {02, 65, 20, 12, 00, 37};
    int n = 6;

    printArray(a, n); // Before Sorting

    selectionSort(a, n);

    printArray(a, n); // Before Sorting

    return 0;
}