#include <iostream>
using namespace std;

void patternSearch(string s, string pat)
{
    int m = s.length();
    int n = pat.length();
    for (int i = 0; n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (s[i] == pat[j])
            {
                        }
        }
    }
}

int main(int argc, char const *argv[])
{
    string s, pattern;
    cout << "Enter the String and the pattern : ";
    cin >> s;
    cin >> pattern;
    patternSearch(s, pattern);
    return 0;
}
