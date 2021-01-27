#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#define INF 987654321
using namespace std;

int board[50][50];
int arr[10][50][50];
int N, M;
int K = 0;
int dnX[] = {0, 0, -1, 1};
int dnY[] = {1, -1, 0, 0};
vector<pair<int, int>> viruses;
int answer = INF;

bool check(vector<int> randoms)
{
    int result = 0;
    int temp[50][50];
    vector<int> virus;

    for (int i = 0; i < randoms.size(); i++)
    {
        if (randoms[i] == 1)
        {
            virus.push_back(i);
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 0)
            {
                int tmp = INF;
                for (int z = 0; z < M; z++)
                {
                    int vi = virus[z];
                    if (arr[vi][i][j] > 0)
                    {
                        tmp = min(tmp, arr[vi][i][j]);
                    }
                }
                if (tmp == INF)
                {
                    return false;
                }
                else
                {
                    result = max(result, tmp);
                }
            }
        }
    }
    answer = min(answer, result);
    return true;
}

void bfs(int row, int col, int k)
{
    queue<pair<int, int>> que;
    que.push(make_pair(row, col));
    arr[k][row][col] = 1;
    while (!que.empty())
    {
        int nowX, nowY, cur;
        nowX = que.front().first;
        nowY = que.front().second;
        cur = arr[k][nowX][nowY];
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextX = nowX + dnX[i];
            int nextY = nowY + dnY[i];
            if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= N)
            {
                continue;
            }
            if ((board[nextX][nextY] == 0 || board[nextX][nextY] == 2) && arr[k][nextX][nextY] == 0)
            {
                arr[k][nextX][nextY] = cur + 1;
                que.push(make_pair(nextX, nextY));
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    int as = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 2)
            {
                bfs(i, j, K);
                K++;
            }
            if (board[i][j] == 0)
            {
                as++;
            }
        }
    }
    if (as == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> randoms;
    for (int i = 0; i < K; i++)
    {
        randoms.push_back(0);
    }
    for (int i = 0; i < M; i++)
    {
        randoms[i] = 1;
    }
    sort(randoms.begin(), randoms.end());
    bool good = false;
    do
    {
        if (check(randoms))
        {
            good = true;
        }

    } while (next_permutation(randoms.begin(), randoms.end()));
    if (answer == INF)
    {
        if (good)
        {
            cout << 0;
            return 0;
        }
        cout << -1 << endl;
    }
    else
    {
        cout << answer - 1 << endl;
    }
}