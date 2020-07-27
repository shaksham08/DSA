#include <iostream>
#include <unordered_set>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter the value of n";
    cin >> n;
    unordered_set<int> st;
    cout << "Enter " << n << " numbers : ";
    int x;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        st.insert(x);
    }

    cout << "The number of distinct elements are : " << st.size();

    return 0;
}
