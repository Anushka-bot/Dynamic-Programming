#include <bits/stdc++.h>
using namespace std;

bool equal_sum(int ele, int arr1[], int arr2[], int r,int t)
{
    if(r != 1)
    {
        arr2[r-1] = arr1[t];
    }
    int sum_arr1 = accumulate(arr1 + 1, arr1 + t, 0);
    int sum_arr2 = accumulate(arr2, arr2 + r, 0);
    if (sum_arr1 == sum_arr2)
    {
        return true;
    }
    else
    {
        return equal_sum(ele, arr1, arr2, r + 1,t-1);
    }
}

int main()
{
    int ele;
    cout << "enter no. of elements: ";
    cin >> ele;
    int input_arr[ele];
    int sec_arr[ele];
    for (int i = 0; i < ele; i++)
    {
        cin >> input_arr[i];
    }
    for (int i = 0; i < ele; i++)
    {
        sec_arr[i] = INT_MIN;
    }
    sort(input_arr, input_arr + ele, greater<int>());
    sec_arr[0] = input_arr[0];
    int r = 1;
    bool a = equal_sum(ele, input_arr, sec_arr, r,ele);
    cout << a;
}