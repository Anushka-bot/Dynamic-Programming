#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a,b;
    cout << "enter strings:" << endl;
    cin >> a >> b;
    int sizea=a.size();
    int sizeb=b.size();
    int t[sizea+1][sizeb+1];
    for(int i=0;i<=sizea;i++)
    {
        for(int j=0;j<=sizeb;j++)
        {
            if(i==0 || j==0)
            {
                t[i][j]=0;
            }
        }
    }
    for(int i=1;i<=sizea;i++)
    {
        for(int j=1;j<=sizeb;j++)
        {
            if(a[i-1] == b[j-1])
            {
                t[i][j]=1+t[i-1][j-1];
            }
            else
            {
                t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
    }
    int length_lcs=t[sizea][sizeb];
    int deletion=sizea-length_lcs;
    int insertion=sizeb-length_lcs;
    cout << "no of deletion: " << deletion << endl;
    cout << "no of insertion: " << insertion << endl;
}