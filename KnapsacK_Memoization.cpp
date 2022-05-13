#include <bits/stdc++.h>
using namespace std;
int t[102][200]; //jonse arguments change hote h in knapsack func uska matrix banta hai

int knapsack(int wei[], int val[], int n, int w)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (t[n - 1][w - 1] != -1)
    {
        return t[n - 1][w - 1];
    }
    else if (wei[n - 1] <= w)
    {
        return t[n - 1][w - 1] = max(val[n - 1] + knapsack(wei, val, n - 1, w - wei[n - 1]), knapsack(wei, val, n - 1, w));
    }
    else
    {
        return t[n - 1][w - 1] = 0;
    }
}
int main()
{
    int n;
    cin >> n;
    int weight[n];
    int value[n];
    int w = 0;
    cout << "Enter weight and Value of items:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
    }
    cout << "enter weight of knapsack: ";
    cin >> w;
    memset(t, -1, sizeof(t));
    int max_profit = knapsack(weight, value, n, w);
    cout << max_profit << endl;
}