/*
Sample Input
------------
3
92 022
82 12
77 13
2 false numeric
Sample Output
-------------
82 12
77 13
92 022
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string extractStringAtKey(string str, int key)
{
    char *temp = (char *)str.c_str();
    char *s = strtok(temp, " ");
    while (key > 1)
    {
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    cin.get();

    string temp;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        getline(cin, temp);
        v.push_back(temp);
    }

    int key;
    string reversal, ordering;
    cin >> key >> reversal >> ordering;

    //1. To extract keys for comparison & store them
    vector<pair<string, string>> vp;
    for (string st : v)
    {
        vp.push_back({st, extractStringAtKey(st, key)});
    }

    //2.sorting according to numerical or lexical
    if (reversal == "")

        return 0;
}
