#include <bits/stdc++.h>
using namespace std;
void subsetsum(int arr[], int range, vector<int> v, int n)
{
    bool t[n + 1][range + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; i <= range; j++)
        {
            if (i == 0)
            {
                t[i][j] = false;
            }
            if (j == 0)
            {
                t[i][j] == true;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= range; j++)
        {
            if (arr[i] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i]] || t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    for (int i = 0; i <= range; i++)
    {
        if (t[n][i] == true)
        {
            v.push_back(t[n][i]);
        }
    }
    cout << "LL" << endl;
    int ans = INT_MAX;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        ans = min(ans, range - 2 * (*it));
    }
    cout << ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int range = accumulate(arr+1, arr + n + 1, 0);
    vector<int> v;
    subsetsum(arr, range, v, n);
}