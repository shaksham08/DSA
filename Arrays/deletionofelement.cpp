//deleting an element in array - the first element found
#include <iostream>

using namespace std;

int deleteatpos(int arr[], int n, int del)
{
    int flag = 1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == del)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {

        for (; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        return n - 1;
    }

    cout << "Element you want to delete is not present in the array" << endl;
    return n;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int del;
    cin >> del;

    n = deleteatpos(arr, n, del);
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
