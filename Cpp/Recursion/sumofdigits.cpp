#include <iostream>

using namespace std;

int sumofdigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n % 10 + sumofdigits(n / 10);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the value of n : ";
    cin >> n;
    int result = sumofdigits(n);
    cout << "The Sum of digits is : ";
    cout << result;
    return 0;
}
