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