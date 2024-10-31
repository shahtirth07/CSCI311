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