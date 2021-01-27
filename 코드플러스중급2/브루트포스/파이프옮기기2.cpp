#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<long long>> arr;
long long dp[32][32][3] = {
    0,
};

int main()
{
    long long result = 0;
    cin >> N;
    arr = vector<vector<long long>>(N, vector<long long>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }
    dp[0][1][0] = 1;
    for (int i = 2; i < N; i++)
    {
        if (arr[0][i] == 0)
        {
            dp[0][i][0] = dp[0][i - 1][0];
        }
    }

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            if (arr[i][j] == 0)
            {
                dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][2];
                dp[i][j][1] = dp[i - 1][j][1] + dp[i - 1][j][2];
                if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0)
                {
                    dp[i][j][2] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][2] + dp[i - 1][j - 1][1];
                }
            }
        }
    }
    cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2] << endl;
}