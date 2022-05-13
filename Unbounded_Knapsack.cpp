#include <bits/stdc++.h>
using namespace std;
int unboundedknapsack(int w[], int v[], int W, int n)
{
    int t[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (w[i] <= j)
            {
                t[i][j] = max(v[i] + t[i][j - w[i]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}
int main()
{
    int n, wok;
    cout << "Enter no. of itmes: ";
    cin >> n;
    cout << "Enter weight of knapsack: ";
    cin >> wok;
    int wei[n + 1], val[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> wei[i] >> val[i];
    }
    int ans = unboundedknapsack(wei, val, wok, n);
    cout << ans;
}