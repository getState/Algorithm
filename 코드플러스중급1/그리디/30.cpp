#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool comparable(char a, char b)
{
    return a > b;
}
int main()
{
    string input;
    cin >> input;
    sort(input.begin(), input.end(), comparable);
    if (input.size() == 1)
    {
        cout << -1 << endl;
    }
    else if (input.size() == 2)
    {
        int temp = stoi(input);
        if (temp % 30 != 0)
        {
            cout << -1;
        }
        else
        {
            cout << temp << endl;
        }
    }
    else if (input[input.size() - 1] != '0')
    {
        cout << -1 << endl;
    }
    else
    {
        int check = 0;
        for (int i = 0; i < input.size(); i++)
        {
            check += (input[i] - '0');
        }
        if (check % 3 != 0)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << input << endl;
        }
    }
}