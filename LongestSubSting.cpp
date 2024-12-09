#include <iostream>
#include <string>
#include <cstring>

using namespace std;

// time complexity O(m*n)
int LSC(char x[], char y[], int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + LSC(x, y, m - 1, n - 1);
    else
        return max(LSC(x, y, m, n - 1), LSC(x, y, m - 1, n));
}

int LSCMemoization(char x[], char y[], int m, int n, int **cache)
{
    cache = new int *[m + 1];
    for (int i = 0; i <= m; i++)
        cache[i] = new int[n + 1];
    if (m == 0 || n == 0)
        return 0;
    if (cache[m][n] != -1)
        return cache[m][n];
    if (x[m - 1] == y[n - 1])
        return cache[m][n] = 1 + LSCMemoization(x, y, m - 1, n - 1, cache);
    else
        return cache[m][n] = max(LSCMemoization(x, y, m, n - 1, cache), LSCMemoization(x, y, m - 1, n, cache));
}

int main()
{
    char x[] = "AGGTAB", y[] = "GXTXAYB";
    int q = sizeof(x) / sizeof(x[0]), w = sizeof(y) / sizeof(y[0]);
    int **cache = new int *[q + 1];
    for (int i = 0; i <= q; i++)
        cache[i] = new int[w + 1];
    memset(cache, -1, sizeof(cache));
    int m = q, n = w;
    cout << "Length of Longest Common Substring is " << LSC(x, y, m, n) << endl;
    cout << "Length of Longest Common Substring is " << LSCMemoization(x, y, m, n, cache) << endl;
    return 0;
}
