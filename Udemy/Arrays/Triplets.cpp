/*
Given an array containing N integers and an number S denoting a target Sum

Find All distinct integers that can add up to form target sum.The numbers in each triplet should be ordered in ascending order,and triplets should be ordered too.

Return empty array is no such triplets exist

Input 
array = [1,2,3,4,5,6,7,8,9,15]
target = 18

OUTPUT
[[1,2,15],
[3,7,8],
[4,6,8],
[5,6,7]]
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Brute Force Approach
//Time Complexity = O(nlogn) + O(n3) = O(n3)
vector<vector<int>> findTripletesBrute(int arr[], int n, int sum)
{
    vector<vector<int>> result;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = i + 2; k < n; k++)
            {
                if (arr[i] < arr[j] && arr[i] < arr[k] && arr[j] < arr[k])
                {
                    if ((arr[i] + arr[j] + arr[k]) == sum)
                    {
                        result.push_back({arr[i], arr[j], arr[k]});
                    }
                }
            }
        }
    }
    return result;
}

//Finding Pairs
vector<vector<int>> findPairsSetDS(int arr[], int start, int n, int sum)
{
    vector<vector<int>> temp;
    int startPoint = start;
    int endPoint = n - 1;
    while (startPoint < endPoint)
    {
        if (arr[startPoint] + arr[endPoint] == sum)
        {
            temp.push_back({arr[start - 1], arr[startPoint], arr[endPoint]});
            startPoint++;
            endPoint++;
        }
        if (arr[startPoint] + arr[endPoint] > sum)
        {
            endPoint--;
        }
        else
        {
            startPoint++;
        }
    }
    return temp;
    ;
}

// Time Complexity : O(n2)
vector<vector<int>> findTripletes(int arr[], int n, int sum)
{
    vector<vector<int>> result;
    sort(arr, arr + n);

    //pick one number and them find other pairs sum
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> temp;
        temp = findPairsSetDS(arr, i + 1, n, sum - arr[i]);
        if (temp.size() > 0)
        {
            for (auto x : temp)
            {
                result.push_back(x);
            }
        }
    }
    return result;
}

// Just More structure way for O(n2)
vector<vector<int>> tripletsStructures(vector<int> arr, int targetSum)
{
    //Logic
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> result;

    // Pick every a[i], pair sum for remaining part
    for (int i = 0; i <= n - 3; i++)
    {

        int j = i + 1;
        int k = n - 1;

        //two pointer approach
        while (j < k)
        {
            int current_sum = arr[i];
            current_sum += arr[j];
            current_sum += arr[k];

            if (current_sum == targetSum)
            {
                result.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
            }
            else if (current_sum > targetSum)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;
    //auto p = findTripletesBrute(arr, 10, sum);
    auto p = findTripletes(arr, 10, sum);
    for (auto x : p)
    {
        for (auto m : x)
        {
            cout << m << " ";
        }
        cout << endl;
    }
    return 0;
}
