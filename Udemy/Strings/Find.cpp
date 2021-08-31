#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> stringSearch(string big, string small)
{
    //store the occurrences in the result vector
    vector<int> result = {};
    int index = big.find(small);
    while (index != -1)
    {
        result.push_back(index);
        index = big.find(small, index + 1);
    }
    return result;
}

int main(int argc, char const *argv[])
{
    std::string s = "We are learning about STL Strings. STL is best for proamming. STL is also quite powerful.";
    std::string word;
    getline(std::cin, word);
    vector<int> result = stringSearch(s, word);
    for (int x : result)
    {
        cout << x << endl;
    }
    return 0;
}
