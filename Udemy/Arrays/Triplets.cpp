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
//Time Complexity = O(n3)
vector<vector<int>> findTripletesBrute(int arr[], int n, int sum)
{
    vector<vector<int>> result;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (i != j && i != k && j != k)
                {
                    if (arr[i] + arr[j] + arr[k] == sum)
                    {
                        result.push_back({arr[i], arr[j], arr[k]});
                    }
                }
            }
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
    int sum = 18;
    auto p = findTripletesBrute(arr, 7, sum);
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
