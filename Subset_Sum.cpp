#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum;
    cout << "no of elements and sum to find" << endl;
    cin >> n >> sum;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    bool t[n + 1][sum + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < sum; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i] <= j)
            {
                t[i][j] = (t[i - 1][j - arr[i]] || t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    cout << t[n][sum] << endl;
}