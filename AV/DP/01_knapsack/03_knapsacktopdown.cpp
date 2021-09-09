#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][1001];

//Top down approach
int maxProfit(int val[], int wt[], int capacity, int n)
{
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < capacity; j++)
        {

            if (wt[n - 1] <= capacity)
            {
                dp[n][capacity] = max(val[n - 1] + dp[n - 1][capacity - wt[n - 1]], dp[n - 1][capacity]);
            }
            else
            {
                dp[n][capacity] = dp[n - 1][capacity];
            }
        }
    }
    return dp[n][capacity];
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
