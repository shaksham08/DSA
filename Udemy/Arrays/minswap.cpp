/*
Given an array of size N, find the minimu number of swaps needed to make the array as sorted

INPUT
a1 = [5,4,3,2,1]

OUTPUT
2

a2 = [10,11,5,4,3,2,1]

OUTPUT
4

SOLUTIONS:

We should know where the element lies i.e the correct location of each element 

1. Sorting = O(NlogN)


*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Time complexity:- O(nlogn)
//Space Complexity :- O(n)
vector<int> subarrysorting(vector<int> a)
{
    vector<int> b(a);
    sort(a.begin(), a.end());

    int i = 0;
    int n = a.size();
    while (i < n && a[i] == b[i])
    {
        i++;
    }
    int j = a.size() - 1;
    while (j >= 0 && a[j] == b[j])
    {
        j--;
    }
    if (i == a.size())
    {
        return {-1, -1};
    }
    return {i, j};
}

// Time Complexity :- O(nlogn)
//Space Complexity :- O(n)
vector<int> subarray(vector<int> arr)
{
    vector<int> maxLeft, minRight;
    int n = arr.size();
    int maximumValue = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maximumValue)
        {
            maximumValue = arr[i];
        }
        maxLeft.push_back(maximumValue);
    }
    int minimumValue = arr[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] < minimumValue)
        {
            minimumValue = arr[i];
        }
        minRight.push_back(minimumValue);
    }
    reverse(minRight.begin(), minRight.end());
    int start = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < maxLeft[i] || arr[i] > minRight[i])
        {
            start = i;
            break;
        }
    }
    int end = -1;
    if (start != -1)
    {

        for (int i = start; i < n; i++)
        {
            if (arr[i] < maxLeft[i] || arr[i] > minRight[i])
            {
                end = i;
            }
        }
    }
    return {start, end};
}

//COrrect Solution
//Time Complexity :- O(n);
//Space Complexoty:- O(1);
bool outOfOrder(vector<int> arr, int i)
{
    int x = arr[i];
    if (i == 0)
    {
        return x > arr[1];
    }
    if (i == arr.size() - 1)
    {
        return x < arr[i - 1];
    }
    return x > arr[i + 1] || x < arr[i - 1];
}

pair<int, int> subarraySort(vector<int> arr)
{

    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        int x = arr[i];

        if (outOfOrder(arr, i))
        {
            smallest = min(smallest, x);
            largest = max(largest, x);
        }
    }

    //next step find the right index where smallest and largest lie (subarray) for out solution
    if (smallest == INT_MAX)
    {
        return {-1, -1};
    }

    int left = 0;
    while (smallest >= arr[left])
    {
        left++;
    }
    int right = arr.size() - 1;
    while (largest <= arr[right])
    {
        right--;
    }

    return {left, right};
}

int main()
{

    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> result = subarray(arr);
    cout << "{" << result[0] << " , " << result[1] << "}\n";
    return 0;
}