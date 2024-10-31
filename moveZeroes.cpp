// C++ program to move all zeroes at the end of the array

void moveZeroes(int arr[], int size)
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