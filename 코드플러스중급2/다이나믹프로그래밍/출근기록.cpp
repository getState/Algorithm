#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<vector<vector<string>>> dp(51, vector<vector<string>>(51, vector<string>(51, "")));
    string input;
    cin >> input;

    dp[1][1][0] = "A";
    dp[1][0][1] = "B";
    dp[1][0][0] = "C";
    for (int i = 1; i < 50; i++)
    {
        for (int a = 0; a <= i; a++)
        {
            for (int b = 0; b <= i; b++)
            {
                int c = i - a - b;
                if (dp[i][a][b] != "")
                {
                    dp[i + 1][a + 1][b] = dp[i][a][b] + "A";
                    if (dp[i][a][b][i - 1] != 'B')
                    {
                        dp[i + 1][a][b + 1] = dp[i][a][b] + "B";
                    }
                    if (dp[i][a][b][i - 1] != 'C')
                    {
                        if (i > 1)
                        {
                            if (dp[i][a][b][i - 2] != 'C')
                            {
                                dp[i + 1][a][b] = dp[i][a][b] + "C";
                            }
                        }
                        else
                        {
                            dp[i + 1][a][b] = dp[i][a][b] + "C";
                        }
                    }
                }
            }
        }
    }
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == 'A')
        {
            a++;
        }
        else if (input[i] == 'B')
        {
            b++;
        }
        else
        {
            c++;
        }
    }
    if (dp[input.size()][a][b] == "")
    {
        cout << -1 << endl;
    }
    else
    {
        cout << dp[input.size()][a][b] << endl;
    }
}