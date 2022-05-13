// Given a string of size 'n'. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
// Examples: Input : aebcbda, Output : 2
// Remove characters 'e' and 'd'
// Resultant string will be 'abcba'
// which is a palindromic string
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
    int length_lcs = t[sizea][sizeb];
    int no_of_deletion = s.size()-length_lcs;
    cout << no_of_deletion << endl;
}