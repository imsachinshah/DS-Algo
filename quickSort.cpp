#include <iostream>
using namespace std;

void printArray(int A[], int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    cout << "\n";
}

int partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do{
        while(A[i] <= pivot)
            i++;
        
        while(A[j] > pivot)
            j--;

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i < j);

    // Swapping pivot to its position

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
    
}

void quickSort(int A[], int low, int high){

    int partitionIndex;

    if(low < high){

        partitionIndex = partition(A, low, high);

        printArray(A, 6);

        quickSort(A, low, partitionIndex - 1); // sort left Part

        quickSort(A, partitionIndex + 1, high); // sort right part
    }
}

int main() {

    int a[] = {2, 65, 20, 12, 0, 37};
    int n = 6;
    

    printArray(a, n); // Before Sorting

    quickSort(a, 0, n-1);

    printArray(a, n); // Before Sorting

    return 0;
}
