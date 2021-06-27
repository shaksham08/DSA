// Problem statement : Given an array(or string), the task is to reverse the array / string.
// Examples:
// Input : arr[] = {1, 2, 3} Output : arr[] = {3, 2, 1}
// Input : arr[] = {4, 5, 1, 2} Output : arr[] = {2, 1, 5, 4}

/* 
Here we are iterating over the half array and just swapping the values.
We can also make use of two pointer method to solve the problem
*/

#include <iostream>

void reverse(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
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
    reverse(arr, n);
    std::cout << "The value stored in array after reversing it it : ";
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    return 0;
}
