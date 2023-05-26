#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

void merge(int arr[], int left, int mid, int right)
{

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        arr1[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        arr2[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k] = arr1[i];
            i++;
            k++;
        }
        else
        {
            arr[k] = arr2[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = arr1[i];
        i++;
        j++;
    }

    while (j < n2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
}

void mergeSort(int arr[], int left, int right)
{

    if (left < right)
#pragma omp parallel sections
    {
        int mid = left + (right - left) / 2;
#pragma omp section
        mergeSort(arr, left, mid);
#pragma omp section
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 4, 5, 6, 7, 7, 2, 2, 75, 7, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting ";
    printArray(arr, n);
    mergeSort(arr, 0, n - 1);

    cout << "After Sorting ";
    printArray(arr, n);
    return 0;
}