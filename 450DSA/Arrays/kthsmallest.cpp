#include <iostream>
#include <queue>

using namespace std;

int kthmin(int arr[], int n, int k)
{
    priority_queue<int> maxh;
    for (int i = 0; i < n; i++)
    {
        maxh.push(arr[i]);
        if (maxh.size() > k)
        {
            maxh.pop();
        }
    }
    return maxh.top();
}

int main(int argc, char const *argv[])
{
    int n;
    std::cout << "Enter the total number of items : ";
    std::cin >> n;
    int arr[n];
    std::cout << "Enter the total value of K : ";
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    cout << kthmin(arr, n, k) << endl;
    return 0;
}