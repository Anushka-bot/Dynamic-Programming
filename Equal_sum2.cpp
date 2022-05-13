#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ele;
    cin >> ele;
    int arr[ele+1];
    for (int i = 1; i <= ele; i++)
    {
        cin >> arr[i];
    }
    int sum = accumulate(arr + 1, arr + ele + 1, 0);
    cout << sum << endl;
    if (sum % 2 == 0)
    {
        bool t[ele + 1][(sum / 2) + 1];
        for (int i = 0; i <= ele; i++)
        {
            for (int j = 0; j <= sum / 2; j++)
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
            for (int i = 1; i <= ele; i++)
            {
                for (int j = 1; j <= sum / 2; j++)
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
        }
        cout << t[ele][sum / 2] << endl;
    }
    else
    {
        cout << "no subset can be formed" << endl;
    }
}