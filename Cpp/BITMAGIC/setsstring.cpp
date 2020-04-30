#include <bits/stdc++.h>

using namespace std;

void subsets(string s, int n)
{
    int powset = pow(2, 3);
    for (int i = 0; i < powset; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((i & (1 << j)) != 0)
            {
                cout << s[j] << " ";
            }
        }
        cout << "\n";
    }
}

int main(int argc, char const *argv[])
{
    string s = "abc";
    subsets(s, 3);
    return 0;
}
