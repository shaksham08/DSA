#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
    int start = 0;
    int end = s.length() - 1;
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter the string to check for panlindrome : ";
    cin >> s;
    if (palindrome(s))
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}
