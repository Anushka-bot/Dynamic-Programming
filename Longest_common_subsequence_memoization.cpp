#include <bits/stdc++.h>
using namespace std;
int t[1001][1001];
int LCS_memoization(string a, string b, int sizea, int sizeb)
{
    if (sizea == 0 || sizeb == 0)
    {
        return t[sizea - 1][sizeb - 1] = 0;
    }
    if (t[sizea - 1][sizeb - 1] != -1)
    {
        return t[sizea - 1][sizeb - 1];
    }
    else
    {
        if (a[sizea - 1] == b[sizeb - 1])
        {
            return t[sizea - 1][sizeb - 1] = 1 + LCS_memoization(a, b, sizea - 1, sizeb - 1);
        }
        else
        {
            return t[sizea - 1][sizeb - 1] = max(LCS_memoization(a, b, sizea - 1, sizeb), LCS_memoization(a, b, sizea, sizeb - 1));
        }
    }
}
int main()
{
    string s1, s2;
    cout << "enter strings:" << endl;
    cin >> s1 >> s2;
    memset(t,-1,sizeof(t));
    int ans = LCS_memoization(s1, s2, s1.size(), s2.size());
    cout << ans << endl;
}