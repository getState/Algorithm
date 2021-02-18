#include <iostream>
#include <vector>
using namespace std;

int main()
{
    while (true)
    {
        int N;
        cin >> N;
        if (N == 0)
        {
            break;
        }
        vector<vector<long long>> dp(N * 2 + 1, vector<long long>(31, 0));
        dp[0][N] = 1;
        for (int i = 0; i < 2 * N; i++)
        {
            for (int j = 0; j < 31; j++)
            {
                long long divided = (N - j) * 2 - i;
                if (divided > 0)
                {
                    dp[i + 1][j] += dp[i][j];
                    if (j > 0)
                    {
                        dp[i + 1][j - 1] += dp[i][j];
                    }
                }
                else
                {
                    if (j > 0)
                    {
                        dp[i + 1][j - 1] += dp[i][j];
                    }
                }
            }
        }
        cout << dp[2 * N][0] << endl;
    }
}