// unbounded knapsack

#include <iostream>

using namespace std;

int maxProfit(int arr[], int val[], int capacity, int n)
{
    int t[n + 1][capacity + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < capacity + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < capacity + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - arr[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][capacity];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *val = new int[n];
    int *wt = new int[n];
    int capacity;
    for (int i = 0; i < n; i++)
    {
        cin >> val[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i];
    }

    cin >> capacity;

    cout << maxProfit(wt, val, capacity, n) << endl;
    delete[] val;
    delete[] wt;
    return 0;
}
