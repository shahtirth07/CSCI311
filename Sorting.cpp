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
    while (int i < size)
    {
        
    }
}
int main()
{
    int arr[] = {64, 34, 25, 12, 11, 90, 1};
    printArray(arr, 7);
    bubbleSort(arr, 7);
    printArray(arr, 7);
}