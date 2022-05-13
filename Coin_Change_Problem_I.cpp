// Coin Change Problem Maximum Number of ways
// Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter.
#include <bits/stdc++.h>
using namespace std;
int coin_change(int coins[], int n, int s)
{
    int t[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (coins[i] <= j)
            {
                t[i][j] = t[i][j - coins[i]] + t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][s];
}
int main()
{
    int no_of_coins, sum;
    cout << "Enter no. of coins: ";
    cin >> no_of_coins;
    cout << "Enter sum: ";
    cin >> sum;
    int arr[no_of_coins + 1];
    for (int i = 1; i <= no_of_coins; i++)
    {
        cin >> arr[i];
    }
    int ans = coin_change(arr, no_of_coins, sum);
    cout << ans;
}