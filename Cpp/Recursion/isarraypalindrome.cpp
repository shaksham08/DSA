#include <iostream>

using namespace std;

bool checkPlindrome(int *arr, int start, int end)
{
    if (start == end || start > end)
    {
        return true;
    }
    return (arr[start] == arr[end] && checkPlindrome(arr, start + 1, end - 1));
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the value of n";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (checkPlindrome(arr, 0, n - 1))
    {
        cout << "Its a Palindrome";
    }
    else
    {
        cout << "Its not a palindrome";
    }
    return 0;
}
