#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> arr;
int start, ending;
int N, M;

bool bfs(int limit)
{
    queue<int> que;
    que.push(start);
    vector<bool> check(N + 1, false);

    while (!que.empty())
    {
        int now = que.front();
        que.pop();
        if (now == ending)
        {
            return true;
        }
        for (int i = 0; i < arr[now].size(); i++)
        {
            int next = arr[now][i].first;
            int nextWeight = arr[now][i].second;
            if (limit <= nextWeight && check[next] == false)
            {
                check[next] = true;
                que.push(next);
            }
        }
    }
    return false;
}

int main()
{

    cin >> N >> M;
    arr = vector<vector<pair<int, int>>>(N + 1);
    for (int i = 0; i < M; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        arr[from].push_back(make_pair(to, weight));
        arr[to].push_back(make_pair(from, weight));
    }

    cin >> start >> ending;

    int left = 0;
    int right = 1000000000;
    int result = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (bfs(mid))
        {
            if (result < mid)
            {
                result = mid;
            }
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result << endl;
}