// Problem statement :- Given an array which consists of only 0, 1 and 2. Sort the array without using any sorting algo
// Link :- https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1

#include <iostream>

using namespace std;

void sorting(int arr[], int n)
{
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            c0++;
        if (arr[i] == 1)
            c1++;
        if (arr[i] == 2)
            c2++;
        int k = 0;
        for (int i = 0; i < c0; i++)
            arr[k++] = 0;
        for (int i = 0; i < c1; i++)
            arr[k++] = 1;
        for (int i = 0; i < c2; i++)
            arr[k++] = 2;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Enter the total number of items : ";
    std::cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    sorting(arr, n);
    std::cout << "The value stored in array after sorting the array is : ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
