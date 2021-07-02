#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// O(nlogn)
int longestBand(vector<int> arr)
{
    //O(nlogn)
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int result = 0;
    if (n == 1)
    {
        return 1;
    }
    // O(n)
    for (int i = 0; i < n - 1; i++)
    {
        int count = 0;
        while (abs(arr[i + 1] - arr[i]) == 1 && i < n)
        {
            count++;
            i++;
        }

        result = max(result, count + 1);
        count = 0;
    }
    return result;
}

//O(n)
int longestBandSetDS(vector<int> arr)
{
    unordered_set<int> st;
    int n = arr.size();
    for (auto x : arr)
    {
        st.insert(x);
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (st.find(arr[i] - 1) == st.end())
        {
            int tempCount = 0;
            int temporaryValue = arr[i];
            while (st.find(temporaryValue) != st.end())
            {
                temporaryValue++;
                tempCount++;
            }
            count = max(count, tempCount);
        }
    }
    return count;
}

int largestBandSol(vector<int> arr)
{
    int n = arr.size();
    unordered_set<int> s;

    //Data inside a set
    for (int x : arr)
    {
        s.insert(x);
    }

    //Iterate over the arr
    int largestLen = 1;

    for (auto element : s)
    {
        int parent = element - 1;

        if (s.find(parent) == s.end())
        {
            //find entire band / chain starting from element
            int next_no = element + 1;
            int cnt = 1;

            while (s.find(next_no) != s.end())
            {
                next_no++;
                cnt++;
            }

            if (cnt > largestLen)
            {
                largestLen = cnt;
            }
        }
    }

    return largestLen;
}

int main()
{

    vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};

    cout << longestBand(arr) << endl;
    cout << longestBandSetDS(arr) << endl;
    cout << largestBandSol(arr) << endl;
    return 0;
}