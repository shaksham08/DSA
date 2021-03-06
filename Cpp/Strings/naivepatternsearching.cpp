#include <iostream>
using namespace std;

void patternSearch(string txt, string pat)
{
    int M = pat.length();
    int N = txt.length();

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++)
    {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            cout << "Pattern found at index "
                 << i << endl;
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
