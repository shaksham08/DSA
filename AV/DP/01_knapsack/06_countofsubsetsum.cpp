#include <iostream>

using namespace std;

int subsetsum(int arr[], int sum, int n)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            if (j == 0)
            {
                dp[i][j] = 1;
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
    return dp[n][sum];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int *arr = new int[n];
    int sum;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> sum;
    cout << subsetsum(arr, sum, n) << endl;
    return 0;
}
