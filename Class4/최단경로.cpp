#include <iostream>
#include <vector>
#include <queue>
#define MAX 20010
#define INF 987654321
using namespace std;
vector<pair<int, int>> graph[MAX];
int Dist[MAX];
int V, E, start;

void dijkstra()
{
    priority_queue<pair<int, int>> pq; //pair<비용, 정점>
    pq.push(make_pair(0, start));
    Dist[start] = 0;
    while (!pq.empty())
    {
        int cost = -pq.top().first; //우선순위 큐에선 큰값이 앞에 오므로 작은 값을 앞에 오게 만드려면 -를 붙인다.
        int current = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[current].size(); i++)
        {
            int next = graph[current][i].first;
            int nextCost = graph[current][i].second;
            if (Dist[next] > cost + nextCost)
            {
                Dist[next] = cost + nextCost;
                pq.push(make_pair(-Dist[next], next));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    cin >> start;
    for (int i = 0; i < E; i++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    for (int i = 1; i <= V; i++)
    {
        Dist[i] = INF; //각 정점까지 가는데 걸리는 비용을 INF로 초기화
    }

    dijkstra();
    for (int i = 1; i <= V; i++)
    {
        if (Dist[i] == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << Dist[i] << endl;
        }
    }
}