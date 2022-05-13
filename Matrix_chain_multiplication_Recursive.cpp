#include <bits/stdc++.h>
using namespace std;
int solve(int a[], int i, int j)
{
    if (i >= j)
    {
        return 0;
    }
    int temp = 0, ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        temp = solve(a, i, k) + solve(a, k + 1, j) + a[i - 1] * a[k] * a[j];
        ans = min(ans, temp);
    }
    return ans;
}
int main()
{
    int no_of_matrix;
    cout << "enter no of matrix" << endl;
    cin >> no_of_matrix;
    int arr[no_of_matrix + 1];
    cout << "enter dimensfions of matrix in array" << endl;
    for (int i = 0; i < no_of_matrix; i++)
    {
        cin >> arr[i];
    }
    int ans = solve(arr, 1, no_of_matrix);
    cout << ans;
}
