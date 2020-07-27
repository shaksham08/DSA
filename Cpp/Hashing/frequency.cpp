#include <iostream>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    unordered_map<int, int> mp;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp[x]++;
    }
    for (auto x : mp)
    {
        cout << x.first << " - " << x.second << endl;
    }
    return 0;
}
