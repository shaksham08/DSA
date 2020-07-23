#include <iostream>

using namespace std;

int printSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + printSum(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the value of N";
    cin >> n;
    int result = printSum(n);
    cout << "The answer is " << result;
    return 0;
}
