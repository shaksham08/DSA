#include <bits/stdc++.h>
using namespace std;

string reverseword(string s)
{
    string reversed = "";
    int start = 0;
    int end = s.length();
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ' || i == 0)
        {
            if (i != 0)
            {
                start = i + 1;
            }
            else
            {
                start = i;
            }
            reversed = reversed + s.substr(start, end - start) + " ";
            end = i;
        }
    }
    return reversed;
}

int main(int argc, char const *argv[])
{
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    string sreversed = reverseword(s);
    cout << sreversed;
    return 0;
}
