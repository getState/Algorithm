#include <iostream>
#include <vector>
using namespace std;
vector<vector<vector<vector<string>>>> dp(31, vector<vector<vector<string>>>(31, vector<vector<string>>(31, vector<string>(450, ""))));
int main()
{
    int N, K;
    cin >> N >> K;

    dp[1][0][0][0] = "C";
    dp[1][1][0][0] = "A";
    dp[1][0][1][0] = "B";
    for (int i = 1; i < 30; i++)
    {
        for (int a = 0; a <= i; a++)
        {
            for (int b = 0; b <= i; b++)
            {
                int c = i - a - b;
                for (int k = 0; k < 450; k++)
                {
                    if (dp[i][a][b][k] != "")
                    {
                        if (dp[i + 1][a + 1][b][k] == "")
                        {
                            dp[i + 1][a + 1][b][k] = dp[i][a][b][k] + "A";
                        }
                        if (dp[i + 1][a][b + 1][k + a] == "")
                        {
                            dp[i + 1][a][b + 1][k + a] = dp[i][a][b][k] + "B";
                        }
                        if (dp[i + 1][a][b][k + a + b] == "")
                        {
                            dp[i + 1][a][b][k + a + b] = dp[i][a][b][k] + "C";
                        }
                    }
                }
            }
        }
    }

    for (int a = 0; a < N + 1; a++)
    {
        for (int b = 0; b < N + 1; b++)
        {
            if (dp[N][a][b][K] != "")
            {
                cout << dp[N][a][b][K] << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}