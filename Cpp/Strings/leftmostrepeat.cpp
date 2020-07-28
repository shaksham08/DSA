#include <iostream>
using namespace std;
int leftmost(string s)
{
    int arr[256] = {0};
    for (int i = 0; i < s.length(); i++)
    {
        if (arr[s[i]] != 0)
        {
            return i;
        }
        else
        {
            arr[s[i]]++;
        }
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int index = leftmost(s);
    if (index == -1)
    {
        cout << "NOT FOUND";
    }
    else
    {
        cout << s[index];
    }
    return 0;
}
