#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(1001, -1);

int main()
{
    int N;
    cin >> N;
    string input;
    cin >> input;
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        char c = input[i];
        int now = dp[i];
        if (now == -1)
        {
            continue;
        }
        for (int j = i + 1; j < N; j++)
        {
            char next = input[j];
            int cost = (j - i) * (j - i);
            if (c == 'B' && next == 'O')
            {
                if (dp[j] == -1)
                {
                    dp[j] = now + cost;
                }
                else
                {
                    dp[j] = min(dp[j], now + cost);
                }
            }
            else if (c == 'O' && next == 'J')
            {
                if (dp[j] == -1)
                {
                    dp[j] = now + cost;
                }
                else
                {
                    dp[j] = min(dp[j], now + cost);
                }
            }
            else if (c == 'J' && next == 'B')
            {
                if (dp[j] == -1)
                {
                    dp[j] = now + cost;
                }
                else
                {
                    dp[j] = min(dp[j], now + cost);
                }
            }
        }
    }
    cout << dp[N - 1] << endl;
}