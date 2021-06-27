/* 
 Problem Statement :- Given an array arr[] and a number K where K is smaller than size of array, the task is to find the Kth smallest element in the given array. It is given that all array elements are distinct.
 link :- https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
*/

#include <iostream>
#include <queue>

using namespace std;
// Here we make use of maxHeap To solve the Problem
//The time complexity for this solution is  N + klog(N)
// N -> for creating a heap and k is for poping the k elements and log N is whenever we pop we need to heapify
// For this question even we can use quick select algorithm , it works on partition algorithm same as quick sort algorithm
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