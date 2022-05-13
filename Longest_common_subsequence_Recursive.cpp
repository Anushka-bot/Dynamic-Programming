//Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous. For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
#include <bits/stdc++.h>
using namespace std;
int LCS(string a, string b, int sizea, int sizeb)
{
    if (sizea == 0 || sizeb == 0)
    {
        return 0;
    }
    else
    {
        if (a[sizea - 1] == b[sizeb - 1])
        {
            return 1 + LCS(a, b, sizea - 1, sizeb - 1);
        }
        else
        {
            return max(LCS(a, b, sizea - 1, sizeb), LCS(a, b, sizea, sizeb - 1));
        }
    }
}
int main()
{
    string s1, s2;
    cout << "enter 2 strings:" << endl;
    cin >> s1 >> s2;
    int ans = LCS(s1, s2, s1.size(), s2.size());
    cout << ans << endl;
}