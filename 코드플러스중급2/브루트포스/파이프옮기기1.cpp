#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int N;
vector<vector<int>> arr;

bool check(tuple<int, int, int> now)
{
    int x, y, direction;
    tie(x, y, direction) = now;
    if (direction == 0)
    {
        if (y + 1 < N && arr[x][y + 1] == 0)
        {
            return true;
        }
    }
    else if (direction == 1)
    {
        if (x + 1 < N && arr[x + 1][y] == 0)
        {
            return true;
        }
    }
    else
    {
        if (x + 1 < N && y + 1 < N && arr[x + 1][y] == 0 && arr[x][y + 1] == 0 && arr[x + 1][y + 1] == 0)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    long long result = 0;
    cin >> N;
    arr = vector<vector<int>>(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    queue<tuple<int, int, int>> que;
    que.push(make_tuple(0, 0, 0));
    while (!que.empty())
    {
        int nowX, nowY, nowDir;
        tie(nowX, nowY, nowDir) = que.front();
        que.pop();
        int nextX, nextY;
        if (nowDir == 0)
        {
            nextX = nowX;
            nextY = nowY + 1;
            if (check(make_tuple(nextX, nextY, 0)))
            {
                que.push(make_tuple(nextX, nextY, 0));
            }
            if (check(make_tuple(nextX, nextY, 2)))
            {
                que.push(make_tuple(nextX, nextY, 2));
            }
        }
        else if (nowDir == 1)
        {
            nextX = nowX + 1;
            nextY = nowY;
            if (check(make_tuple(nextX, nextY, 1)))
            {
                que.push(make_tuple(nextX, nextY, 1));
            }
            if (check(make_tuple(nextX, nextY, 2)))
            {
                que.push(make_tuple(nextX, nextY, 2));
            }
        }
        else
        {
            nextX = nowX + 1;
            nextY = nowY + 1;
            if (check(make_tuple(nextX, nextY, 0)))
            {
                que.push(make_tuple(nextX, nextY, 0));
            }
            if (check(make_tuple(nextX, nextY, 1)))
            {
                que.push(make_tuple(nextX, nextY, 1));
            }
            if (check(make_tuple(nextX, nextY, 2)))
            {
                que.push(make_tuple(nextX, nextY, 2));
            }
        }
        if (nextX == N - 1 && nextY == N - 1)
        {
            result++;
        }
    }
    cout << result << endl;
}