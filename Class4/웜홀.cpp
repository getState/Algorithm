#include <iostream>
#include <vector>
#define INF 987654321
#define MAX 501
using namespace std;
int N, M, W;

bool belmanFord(vector<vector<pair<int, int>>> graph, vector<int> dist, int start)
{
    dist[start] = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int z = 0; z < graph[j].size(); z++)
            {
                int next = graph[j][z].first;
                int nextCost = dist[j] + graph[j][z].second;
                if (dist[next] > nextCost)
                {
                    if (i == N - 1)
                    {
                        return true;
                    }
                    dist[next] = nextCost;
                }
            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> N >> M >> W;
        vector<vector<pair<int, int>>> graph(N + 1);
        vector<int> dist(N + 1, INF); //정점
        for (int i = 0; i < M; i++)
        {
            int from, to, cost;
            cin >> from >> to >> cost;
            graph[from].push_back(make_pair(to, cost));
            graph[to].push_back(make_pair(from, cost));
        }
        for (int i = 0; i < W; i++)
        {
            int from, to, cost;
            cin >> from >> to >> cost;
            graph[from].push_back(make_pair(to, -cost));
        }
        bool result = belmanFord(graph, dist, 1);
        if (result)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}