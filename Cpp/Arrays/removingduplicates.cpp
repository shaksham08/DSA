//removing duplicates from sorted array
#include <bits/stdc++.h>

using namespace std;

void removeduplicates(int *arr, int *n)
{
    int temp = arr[0];
    int pos = 1;
    for (int i = 1; i < *n; i++)
    {
        if (arr[i] != temp)
        {
            arr[pos] = arr[i];
            pos++;
            temp = arr[i];
        }
    }
    *n = pos;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    removeduplicates(arr, &n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}