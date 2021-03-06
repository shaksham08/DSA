// Problem statement :Write a C function to return minimum and maximum in an array. Your program should make the minimum number of comparisons.

// Time complexity = O(n)

#include <iostream>
#include <climits>

void minmax(int arr[], int n)
{
    int min = INT_MAX;
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    std::cout << min << " " << max;
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Enter the total number of items : ";
    std::cin >> n;
    int arr[100];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    minmax(arr, n);
    return 0;
}
