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

void insertionSort(int A[], int n){

    int key, j;

    for(int i = 1; i <= n-1; i++){

        key = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > key)
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = key;
        
    }
}

int main()
{
    // Dry Run
    //   -1  0   1   2   3   4   5  
    //       02, 65, 20, 12, 00, 37

    // First Pass
    //       02,|65, 20, 12, 00, 37  i = 1, key = 65, j = 0


    // Second Pass
    //       02, 65,|20, 12, 00, 37  i = 2, key = 20, j = 1
    //       02, 20,|20, 12, 00, 37  i = 2, key = 20, j = 0
    //       02, 20,|65, 12, 00, 37  i = 2, key = 20, j = -1

    // Third Pass
    //       02, 20, 65,|12, 00, 37  i = 3, key = 12, j = 2
    //       02, 20, 12,|12, 00, 37  i = 3, key = 12, j = 1
    //       02, 12, 20,|12, 00, 37  i = 3, key = 12, j = 0
    //       02, 12, 20,|65, 00, 37  i = 3, key = 12, j = -1

    // Fourth Pass
    //       02, 12, 20, 65,|00, 37  i = 4, key = 00, j = 3
    //       02, 12, 20, 00,|00, 37  i = 4, key = 00, j = 3
    //       02, 12, 00, 20,|00, 37  i = 4, key = 00, j = 2
    //       02, 00, 12, 20,|00, 37  i = 4, key = 00, j = 1
    //       00, 02, 12, 20,|00, 37  i = 4, key = 00, j = 0
    //       00, 02, 12, 20,|65, 37  i = 4, key = 00, j = -1

    // Fifth pass
    //       00, 02, 12, 20, 65,|37  i = 5, key = 37, j = 4
    //       00, 02, 12, 20, 37,|37  i = 5, key = 37, j = 4
    //       00, 02, 12, 20, 37,|65  i = 5, key = 37, j = 3



    int a[] = {2, 65, 20, 12, 0, 37};
    int n = 6;

    printArray(a, n); // Before Sorting

    insertionSort(a, n);

    printArray(a, n); // Before Sorting

    return 0;
}