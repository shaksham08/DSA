/*
Maximum Subarray Sum

Implement a function that takes an input a vector of integers, and
prints the maximum subarray sum that can be formed. A subarray
is defined as consecutive segment of the array. If all numbers are
negative, then return 0.

Hint
Expected Time Complexity
O(N)
Space Complexity 
O(1)

Input
{-1,2,3,4,-2,6,-8,3}

Output
13
*/

#include <iostream>
#include <vector>

using namespace std;

int maximumSubArraySum(vector<int> arr)
{
    //kdanes algo
    int maxSum = arr[0];
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        maxSum = max(maxSum, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return maxSum > 0 ? maxSum : 0;
}

int main()
{

    vector<int> arr{-2, -3, 4, -1, -2, 1, 5, -3};

    cout << maximumSubArraySum(arr);

    return 0;
}