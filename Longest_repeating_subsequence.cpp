// Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
// Example: Input: str = "aab",Output: 1
// The two subsequence are 'a'(first) and 'a' 
// (second). Note that 'b' cannot be considered 
// as part of subsequence as it would be at same
// index in both.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    cout << "enter string:" << endl;
    cin >> s1;
    string s2=s1;
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
            if (s1[i-1] == s2[j-1] && i != j)
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