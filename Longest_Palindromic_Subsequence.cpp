// Given a sequence, find the length of the longest palindromic subsequence in it.
// Example : Input:"bbbab" Output:4
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "enter string:" << endl;
    cin >> s;
    string s2 = s;
    reverse(s.begin(),s.end());
    int sizea = s2.size();
    int sizeb = s.size();
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
            if (s2[i-1] == s[j-1])
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