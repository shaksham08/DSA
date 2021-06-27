/*
Given an array containing N integers, and an number S denoting a target Sum

Find two distinct integers that can pair up to form target sum.Let us assume there will be only one such pair.

input

array=[10,5,2,3,-6,9,11]
s=4

output 

[10,-6]

/*

Solutions :-

1. One way of solution is Brute Force Approach where we use two loops and then check for all pairs
    Time Complexity :- O(n2) time
2. Another solution can be using by
    - first sort the array 
    - then search for the element using binary search
    - So total time complexity will be O(nlogn) + O(nlogn) = O(nlogn)
3. The most effiecient solution in terms of time complexity would be using set datastructure as the acces time for it is o(1)
    TIme complexity :- O(n)
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

void findPairBruteForce(int arr[], int n, int sum)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] + arr[j] == sum)
            {
                cout << arr[i] << " + " << arr[j] << " = " << sum;
                return;
            }
        }
    }
}

// Time Complexity :- o(nlogn)
// we can use this to get the element as well.
void findPairsBinarySearch(int arr[], int n, int sum)
{
    //o(nlogn)
    sort(arr, arr + n);
    //0(n)
    for (int i = 0; i < n; i++)
    {
        //We can use this to search
        //o(logn)
        cout << binary_search(arr, arr + n, sum - arr[i]) << " ";
    }
}

vector<int> findPairsSetDS(int arr[], int n, int sum)
{
    unordered_set<int> st;
    for (int i = 0; i < n; i++)
    {
        if (st.find(sum - arr[i]) != st.end())
            return {arr[i], sum - arr[i]};
        st.insert(arr[i]);
    }
    return {};
}

int main(int argc, char const *argv[])
{
    int arr[] = {10, 5, 2, 3, -6, 9, 11};
    int sum = 4;
    //findPairBruteForce(arr, 7, sum);
    //findPairsBinarySearch(arr, 7, sum);
    auto p = findPairsSetDS(arr, 7, sum);
    for (auto x : p)
    {
        cout << x << " ";
    }
    return 0;
}
