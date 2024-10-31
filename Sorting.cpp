#include <iostream>

using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
};

void bubbleSort(int arr[], int n)
{
    int i = n;
    while (i > 0)
    {
        bool isSwapped = false;
        int j = 0;
        while (j < i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isSwapped = true;
            }
            j++;
        }
        if (!isSwapped)
        {
            break;
        }
        --i;
    }
};

void insertionSort(int arr[], int size)
{
    int i = 1;
    while (i < size)
    {
        int j = i - 1;
        while (j >= 0)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                j = j - 1;
            }
            else
            {
                break;
            }
        }
        i++;
    }
}

void selectionSort(int arr[], int size)
{
    int i = 0;
    while (i < size)
    {
        int j = i + 1;
        int bestMinIndex = i;
        while (j < size)
        {
            if (arr[j] < arr[bestMinIndex])
            {
                bestMinIndex = j;
            }
            j++;
        }
        int temp = arr[bestMinIndex];
        arr[bestMinIndex] = arr[i];
        arr[i] = temp;
        i++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // int m = (l + r) / 2; might piss of interviewer overflow and int
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[], int l, int m, int n)
{
    int n1 = m - l + 1;
    int n2 = n - m;
    int L[n1], R[n2];
    int i = 0;
    while (i < n1)
    {
        L[i] = arr[l + i];
        i++;
    }
    int j = 0;
    while (j < n2)
    {
        R[j] = arr[m + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = partition(arr, l, r);
        quickSort(arr, l, m - 1);
        quickSort(arr, m + 1, r);
    }
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;
    int j = l;
    while (j < r)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}

int main()
{
    int arr[] = {64, 34, 25, 12, 11, 90, 1};
    printArray(arr, 7);
    // bubbleSort(arr, 7);
    // printArray(arr, 7);
    cout << "printing insertion sort" << endl;
    insertionSort(arr, 7);
    printArray(arr, 7);
}