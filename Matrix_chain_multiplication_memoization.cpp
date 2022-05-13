#include <bits/stdc++.h>
using namespace std;
int max_size_of_array = 10;
int t[11][11];
int solve_memoi(int a[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    if(t[i][j] != -1)
    {
        return t[i][j];
    }
    int temp;
    for (int k = i; k < j; k++)
    {
        temp = solve_memoi(a, i, k) + solve_memoi(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        t[i][j] = min(temp, t[i][j]);
    }
    return t[i][j];
}
int main()
{
    int size_arr;
    cout << "enter size of aray" << endl;
    cin >> size_arr;
    int arr[size_arr+1];
    cout << "enter dimensfions of matrix in array" << endl;
    for (int i = 1; i <= size_arr; i++)
    {
        cin >> arr[i];
    }
    memset(t,-1,sizeof(t));
    int ans = solve_memoi(arr, 2, size_arr);
    cout << ans;
}
