/*
Given n non negative integers representing an elevation map where the widh of each bar is 1, compute how much water it can trap after raining

input

height=[0,1,0,2,1,0,1,3,2,1,2,1]

output 

6


SOLUTIONS:-

1. First solution is looking for the max buildings on both side for each step.
    Time Complexity : - O(n2)
2. Second solution is to make use of two arrays to store the max left and right heights and then compute the count
    Time Complexity : - O(n)
    Space Complexity :- O(n)

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Time Complexity : O(n2)
int rain(vector<int> height)
{
    int count = 0;
    int n = height.size();
    for (int i = 1; i < n - 1; i++)
    {
        int maxLeft = 0;
        int maxRight = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            maxLeft = max(maxLeft, height[j]);
        }
        for (int j = i + 1; j < n; j++)
        {
            maxRight = max(maxRight, height[j]);
        }
        if ((min(maxLeft, maxRight) - height[i]) > 0)
            count = count + (min(maxLeft, maxRight) - height[i]);
    }
    return count;
}

//Time Complexity :- O(n)
// Space Complexity :- O(n)
int rainDS(vector<int> height)
{
    int count = 0;
    int n = height.size();
    int *rightMaxArr = new int[n];
    int *leftMaxArr = new int[n];
    int maxEl = 0;
    for (int i = 0; i < n; i++)
    {
        leftMaxArr[i] = maxEl;
        maxEl = max(maxEl, height[i]);
    }
    maxEl = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        rightMaxArr[i] = maxEl;
        maxEl = max(maxEl, height[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if ((min(leftMaxArr[i], rightMaxArr[i]) - height[i]) > 0)
            count = count + (min(leftMaxArr[i], rightMaxArr[i]) - height[i]);
    }

    return count;
}

// FInal Solution
int trappedWater(vector<int> heights)
{

    //Complete
    int n = heights.size();
    if (n <= 2)
    {
        return 0;
    }

    //Left Max, Right Max
    vector<int> left(n, 0), right(n, 0);
    left[0] = heights[0];
    right[n - 1] = heights[n - 1];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], heights[i]);
        right[n - i - 1] = max(right[n - i], heights[n - i - 1]);
    }

    //water
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - heights[i];
    }

    return water;
}

int main()
{

    vector<int> arr{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << rainDS(arr);
    return 0;
}