#include <iostream>
#include <string>

using namespace std;

bool checkSubset(string str1, string str2)
{
    int i = str1.length() - 1;
    int j = str2.length() - 1;
    while (i >= 0 && j >= 0)
    {

        if (str1[i] == str2[j])
        {
            i--;
            j--;
        }
        else
        {
            i--;
        }
    }

    if (j == -1)
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string str1;
    string str2;
    cin >> str1 >> str2;
    cout << checkSubset(str1, str2) << endl;
    return 0;
}
