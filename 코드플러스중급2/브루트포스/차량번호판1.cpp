#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s;
    int result = 0;
    cin >> s;
    stack<int> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'c')
        {
            stk.push(26);
        }
        else
        {
            stk.push(10);
        }
    }
    int top = stk.top();
    stk.pop();
    result = top;
    while (!stk.empty())
    {
        if (top == stk.top())
        {
            result = result * (stk.top() - 1);
            stk.pop();
        }
        else
        {
            top = stk.top();
            result = result * stk.top();
            stk.pop();
        }
    }
    cout << result << endl;
}