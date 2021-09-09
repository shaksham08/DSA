#include <iostream>
#include <algorithm>

using namespace std;

//recursive way
int maxProfit(int val[], int wt[], int capacity, int n)
{
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    if (wt[n - 1] <= capacity)
    {
        return max(val[n - 1] + maxProfit(val, wt, capacity - wt[n - 1], n - 1), maxProfit(val, wt, capacity, n - 1));
    }
    else
    {
        return maxProfit(val, wt, capacity, n - 1);
    }
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

    cout << maxProfit(val, wt, capacity, n) << endl;
    delete[] val;
    delete[] wt;
    return 0;
}
