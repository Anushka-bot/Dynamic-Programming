#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int wei[], int pri[], int W)
{
    // cout << "test" << endl;
    // cout << sizeof(wei) << endl;
    // cout << sizeof(pri) << endl;
    // cout << "****" << endl;
    if (n == 0 || W == 0) //Base condition
    {
        return 0;
    }
    if (wei[n - 1] <= W) //Choice Diagram
    {
        return (max(pri[n - 1] + knapsack(n - 1, wei, pri, W - wei[n - 1]), knapsack(n - 1, wei, pri, W)));
    }
    else
    {
        return (knapsack(n - 1, wei, pri, W));
    }
}
int main()
{
    int size, weight_of_knapsack;
    cout << "Enter size of array: ";
    cin >> size;
    cout << "Enter max weight of knapsack: ";
    cin >> weight_of_knapsack;
    int weight[size];
    int price[size];
    cout << "Weight" << " " << "Price" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> weight[i] >> price[i];
    }
    int profit = knapsack(size, weight, price, weight_of_knapsack);
    cout << profit << endl;
}