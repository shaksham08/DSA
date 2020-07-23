#include <iostream>

using namespace std;

bool checkPlindrome(string s, int start, int end)
{
    if (start == end || start > end)
    {
        return true;
    }
    return (s[start] == s[end] && checkPlindrome(s, start + 1, end - 1));
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    if (checkPlindrome(s, 0, s.length() - 1))
    {
        cout << "Its a Palindrome";
    }
    else
    {
        cout << "Its not a palindrome";
    }
    return 0;
}
