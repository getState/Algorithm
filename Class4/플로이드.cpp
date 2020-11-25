#include <iostream>
#define INF 987654321
using namespace std;
int N, M;
int dp[101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            dp[i][j] = INF;
        }
    }
    int from, to, cost;
    for (int i = 0; i < M; i++)
    {
        cin >> from >> to >> cost;
        if (dp[from][to] > cost)
        {
            dp[from][to] = cost;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            for (int z = 1; z <= N; z++)
            {
                if (dp[j][z] > dp[j][i] + dp[i][z])
                {
                    dp[j][z] = dp[j][i] + dp[i][z];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
            {
                cout << 0 << " ";
            }
            else if (dp[i][j] == INF)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << dp[i][j] << " ";
            }
        }
        cout << "\n";
    }
}