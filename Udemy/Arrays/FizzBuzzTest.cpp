/*

Write a function that returns a with the numbers from 1 to n with the following
restrictions: fizzbuzz vector<string>
for multiples of 3 store "Fizz" instead of the number
for multiples of 5 store "Buzz" instead of the number
for numbers which are multiples of both 3 and 5 store "FizzBuzz"
You may use the method to convert a number into a string. std::to_string(number)

Example
1 fizzbuzz(15) == {
2 "1", "2", "Fizz", "4", "Buzz",
3 "Fizz", "7", "8", "Fizz", "Buzz",
4 "11", "Fizz", "13", "14", "FizzBuzz"
5 }

*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n)
{
    vector<string> st;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            st.push_back("FizzBuzz");
        }
        else if (i % 3 == 0)
        {
            st.push_back("Fizz");
        }
        else if (i % 5 == 0)
        {
            st.push_back("Buzz");
        }
        else
        {
            st.push_back(std::to_string(i));
        }
    }
    return st;
}

int main()
{
    vector<string> final;
    final = fizzbuzz(15);
    for (auto x : final)
    {
        cout << x << " ";
    }
}