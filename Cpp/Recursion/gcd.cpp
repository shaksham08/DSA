#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (b != 0)
    {
        return gcd(b, a % b);
    }
    else
    {
        return a;
    }
}

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Enter the two numbers to find gcd : ";
    cin >> a >> b;

    int result = gcd(a, b);
    cout << result;
    return 0;
}
