#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string st;
    getline(cin, st);
    cout << st << endl;
    string result = "";
    for (char ch : st)
    {
        if (ch != ' ')
        {
            result.push_back(ch);
        }
        else
        {
            result.append("%20");
        }
    }
    cout << result << endl;

    return 0;
}
