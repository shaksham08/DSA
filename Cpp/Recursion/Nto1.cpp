#include <iostream>
using namespace std;

void print(int N)
{
    if (N == 0)
    {
        return;
    }

    cout << N << " ";
    print(N - 1);
}

int main(int argc, char const *argv[])
{
    int N;
    cout << "Enter the Value of N: ";
    cin >> N;
    cout << "The 1 to " << N << " are below\n";
    print(N);
    return 0;
}
