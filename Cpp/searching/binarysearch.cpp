#include <iostream>

using namespace std;

bool search(int arr[], int n, int key)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = (high + low) / 2;
        if (arr[mid] == key)
        {
            return true;
        }
        else if (arr[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}
main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the number of element to be entered in the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "ENter the key to be searcherd : ";
    cin >> key;
    if (search(arr, n, key))
    {
        cout << "Key found ";
    }
    else
    {
        cout << "not found";
    }

    return 0;
}
