#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[301][301];
int go(int a, int b)
{
    if (dp[a][b] > 0)
    {
        return dp[a][b];
    }
    if (a == 1 && b == 1)
    {
        return 0;
    }
    int result = 987654321;
    for (int i = 1; i <= a / 2; i++)
    {
        result = min(result, go(i, b) + go(a - i, b) + 1);
    }
    for (int i = 1; i <= b / 2; i++)
    {
        result = min(result, go(a, i) + go(a, b - i) + 1);
    }
    dp[a][b] = result;
    return result;
}
int main()
{
    int N, M;
    cin >> N >> M;
    go(N, M);
    cout << dp[N][M] << endl;
    return 0;
}