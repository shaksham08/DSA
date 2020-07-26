#include <iostream>

using namespace std;
void substring(string s, string t, int length)
{
    if (s.length() == length)
    {
        cout << t << endl;
        return;
    }
    substring(s, t, length + 1);
    t.push_back(s[length]);
    substring(s, t, length + 1);
}

int main(int argc, char const *argv[])
{
    string s = "";
    cout << "Enter the String : ";
    cin >> s;
    substring(s, "", 0);
    return 0;
}
