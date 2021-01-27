#include <iostream>
#include <vector>
using namespace std;

#define MAX 987654321

int main()
{
    int N, M;
    int answer = MAX;
    cin >> N >> M;
    vector<vector<int>> arr(N + 1);
    vector<vector<bool>> check(N + 1, vector<bool>(N + 1, false));
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
        check[from][to] = true;
        check[to][from] = true;
    }
    for (int i = 1; i < N + 1; i++)
    {
        int A = i;
        for (int j = 0; j < arr[A].size(); j++)
        {
            int B = arr[A][j];
            for (int z = 0; z < arr[B].size(); z++)
            {
                int C = arr[B][z];
                if (check[A][B] && check[B][C] && check[A][C])
                {
                    int result = arr[A].size() + arr[B].size() + arr[C].size() - 6;
                    if (answer > result)
                    {
                        answer = result;
                    }
                }
            }
        }
    }
    if (answer == MAX)
    {
        cout << -1;
    }
    else
    {
        cout << answer;
    }
}