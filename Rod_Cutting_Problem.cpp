//COPIED CODE FROM UNBOUNDED KNAPSACK ITS COMPLETELY SAME!!!
#include <bits/stdc++.h>
using namespace std;
int rodcuting(int w[], int v[], int n)
{
    int t[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
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
    return t[n][n];
}
int main()
{
    int n, wok;
    cout << "Enter length of rod: ";
    cin >> n;
    int cuts[n + 1], price[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> cuts[i] >> price[i];
    }
    int ans = rodcuting(cuts, price, n);
    cout << ans;
}