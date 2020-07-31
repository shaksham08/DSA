#include <iostream>

using namespace std;

bool search(int arr[], int low, int high, int key)
{
    if (low > high)
    {
        return false;
    }
    int mid = (low + high) / 2;
    if (arr[mid] == key)
    {
        true;
    }
    else if (arr[mid] > key)
    {
        return search(arr, low, mid - 1, key);
    }
    else
    {
        return search(arr, mid + 1, high, key);
    }
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
    if (search(arr, 0, n, key))
    {
        cout << "Key found ";
    }
    else
    {
        cout << "not found";
    }

    return 0;
}
