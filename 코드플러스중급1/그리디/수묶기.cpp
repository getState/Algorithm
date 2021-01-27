#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int> plus_que;
priority_queue<int, vector<int>, greater<int>> minus_que;

int main()
{
    int N;
    cin >> N;
    int input;
    int zeroCount = 0;
    int oneCount = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        if (input > 1)
        {
            plus_que.push(input);
        }
        else if (input < 0)
        {
            minus_que.push(input);
        }
        else if (input == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }
    int result = 0;
    int now = 0;
    while (!plus_que.empty())
    {
        int next = plus_que.top();
        plus_que.pop();
        if (now == 0)
        {
            now = next;
        }
        else
        {
            result += (now * next);
            now = 0;
        }
    }
    if (now != 0)
    {
        result += now;
    }
    now = 0;
    while (!minus_que.empty())
    {
        int next = minus_que.top();
        minus_que.pop();
        if (now == 0)
        {
            now = next;
        }
        else
        {
            result += (now * next);
            now = 0;
        }
    }
    if (now != 0)
    {
        if (zeroCount == 0)
        {
            result += now;
        }
    }
    cout << result + oneCount << endl;
}