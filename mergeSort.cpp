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

void merge(int A[], int mid, int low, int high)
{

    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {

        if (A[i] < A[j])
        {

            B[k] = A[i];
            i++;
            k++;
        }
        else
        {

            B[k] = A[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
    
}

void mergeSort(int A[], int low, int high)
{
    int mid;

    if (low < high)
    {

        mid = (low + high) / 2;

        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

int main()
{

    int A[] = {4, 2, 10, 8, 56, 7};
    int n = 6;

    printArray(A, n); // Before Sorting

    mergeSort(A, 0, 5);

    printArray(A, n); // Before Sorting

    return 0;
}
