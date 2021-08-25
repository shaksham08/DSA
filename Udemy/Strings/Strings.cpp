#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
    //char s[100] = {'1', '2', '\0'};   // old way for defining string
    //string s = "Hello World";
    //string s("hello world");
    string s;             // Dynamic Array
    getline(cin, s, '.'); // this will take input till we enter a dot
    cout << s << endl;
    for (auto ch : s)
    {
        cout << ch << " ";
    }
    //vector<String> s;
    return 0;
}
