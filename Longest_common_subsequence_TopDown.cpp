#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    cout << "enter strings:" << endl;
    cin >> s1 >> s2;
    int sizea = s1.size();
    int sizeb = s2.size();
    int t[sizea + 1][sizeb + 1];
    for (int i = 0; i <= sizea; i++)
    {
        for (int j = 0; j <= sizeb; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i=1;i<=sizea;i++)
    {
        for (int j=1;j<=sizeb;j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else
            {
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
    }
    cout << t[sizea][sizeb] << endl;
}