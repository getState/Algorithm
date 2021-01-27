#include <iostream>
#include <queue>
using namespace std;

int main()
{
    long long A, B;
    cin >> A >> B;
    if (A == B)
    {
        cout << 1 << endl;
        return 0;
    }
    queue<pair<long long, long long>> que;
    que.push(make_pair(A, 1));
    while (!que.empty())
    {
        long long now = que.front().first;
        long long count = que.front().second;
        que.pop();
        if (now == B)
        {
            cout << count << endl;
            return 0;
        }
        if (now * 2 <= B)
        {
            que.push(make_pair(now * 2, count + 1));
        }
        if (now * 10 + 1 <= B)
        {
            que.push(make_pair(now * 10 + 1, count + 1));
        }
    }
    cout << -1 << endl;
}