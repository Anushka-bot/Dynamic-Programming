#include <bits/stdc++.h>
using namespace std;
int main()
{
    int noi, wok;
    cout << "enter no. of elements: ";
    cin >> noi;
    cout << "enter weight of knapsack: ";
    cin >> wok;
    int wei[noi + 1];
    int val[noi + 1];
    for (int i = 1; i <= noi; i++)
    {
        cin >> wei[i] >> val[i];
    }
    int t[noi + 1][wok + 1];
    for (int i = 0; i <= noi; i++)
    {
        for (int j = 0; j <= wok; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= noi; i++)
    {
        for (int j = 1; j <= wok; j++)
        {
            if (wei[i] <= j)
            {
                t[i][j] = max(val[i] + t[i - 1][j - wei[i]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    cout << "Max profit will be: ";
    cout << t[noi][wok] << endl;
}