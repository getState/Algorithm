#include <iostream>
#include <string.h>
#include <vector>
#include <string>
using namespace std;

string input;

int main()
{
    cin >> input;
    vector<char> opers;
    vector<int> numbers;
    string temp = "";
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '+')
        {
            numbers.push_back(stoi(temp));
            opers.push_back('+');
            temp = "";
        }
        else if (input[i] == '-')
        {
            numbers.push_back(stoi(temp));
            opers.push_back('-');
            temp = "";
        }
        else
        {
            temp += input[i];
        }
    }
    numbers.push_back(stoi(temp));
    for (int i = 0; i < opers.size(); i++)
    {
        if (opers[i] == '-')
        {
            for (int j = i + 1; j < opers.size(); j++)
            {
                opers[j] = '-';
            }
            break;
        }
    }
    int result = numbers[0];
    for (int i = 1; i < numbers.size(); i++)
    {
        if (opers[i - 1] == '+')
        {
            result += numbers[i];
        }
        else
        {
            result -= numbers[i];
        }
    }
    cout << result << endl;
}