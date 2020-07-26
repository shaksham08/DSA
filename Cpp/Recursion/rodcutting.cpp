#include <iostream>
using namespace std;

int rodCutting(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }

    int res = max(max(rodCutting(n - a, a, b, c), rodCutting(n - b, a, b, c)),
                  rodCutting(n - c, a, b, c));
    if (res == -1)
    {
        return -1;
    }
    return res + 1;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the length of the rod";
    cin >> n;
    cout << "Enter the three lengths to be cut";
    int a, b, c;
    cin >> a >> b >> c;
    int result = rodCutting(n, a, b, c);
    cout << "Result : " << result;
    return 0;
}
