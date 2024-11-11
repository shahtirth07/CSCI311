// C++ program to move all zeroes at the end of the array

#include <bits/stdc++.h>

using namespace std;

// time complexity O(n^2)
void moveZeroesWithExtraTime(int arr[], int size)
{
    int j = 0;
    int i = size;
    while (j < i)
    {
        if (arr[j] != 0)
        {
            j++;
        }
        else
        {
            int k = j + 1;
            while (k < i)
            {
                arr[k - 1] = arr[k];
                k++;
            }
            arr[i - 1] = 0;
            i--;
        }
    }
}

// time complexity O(n)
void moveZeroesWithoutExtraTime(int arr[], int size)
{
    int i = 0;
    int j = -1;
    while (i < size)
    {
        if (arr[i] == 0)
        {
            i = i + 1;
        }
        else
        {
            swap(arr[i], arr[j + 1]);
            j = j + 1;
            i = i + 1;
        }
    }
}

int generatePivotAndRearrange(int arr[], int low, int high)
{
    int randomIndex = rand() % (high - low + 1) + low;
    int pivot = arr[randomIndex];
    int i = low;
    int j = low;
    int k = high;
    while (j <= k)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i = i + 1;
            j = j + 1;
        }
        else if (arr[j] > pivot)
        {
            swap(arr[j], arr[k]);
            k = k - 1;
        }
        else
        {
            j = j + 1;
        }
    }
    return i;
}

int generatePivotAndRearrangeWithPivot(int arr[], int low, int high, int pivot)
{
    /* int randomIndex = rand() % (high - low + 1) + low;
    int pivot = arr[randomIndex]; */
    int i = low;
    int j = low;
    int k = high;
    while (j <= k)
    {
        if (arr[j] < pivot)
        {
            swap(arr[i], arr[j]);
            i = i + 1;
            j = j + 1;
        }
        else if (arr[j] > pivot)
        {
            swap(arr[j], arr[k]);
            k = k - 1;
        }
        else
        {
            j = j + 1;
        }
    }
    return i;
}

int medianOfFive(int arr[], int start)
{
    sort(arr + start, arr + start + 5);
    return arr[start + 2];
}

//T(n) = T(n/5) + O(n)
int medianOfMedians(int arr[], int low, int high) 
{
    int n = high - low + 1;
    int medians[(n+4)/5];
    int i = 0;
    for (i = 0; i < n/5; i++) 
    {
        medians[i] = medianOfFive(arr, low + i*5);
    }
    if (i*5 < n) 
    {
        sort(arr + low + i*5, arr + high + 1);
        medians[i] = arr[low + i*5];
    }
    if (i == 1) 
    {
        return medians[0];
    }
    else
    {
        return medianOfMedians(medians, 0, i - 1);
    }
}

// T(n) = N + T(3N/10) + T(7N/10)
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // median of medians
        int pivotValue = medianOfMedians(arr, low, high);
        int pivotIndex = generatePivotAndRearrangeWithPivot(arr, low, high, pivotValue);
        quickSort(arr, low, pivotIndex - 1);  // left partition
        quickSort(arr, pivotIndex + 1, high); // right partition
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {0, 1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    // moveZeroesWithoutExtraTime(arr, size);
    quickSort(arr, 0, size - 1);
    printArray(arr, size);
}
