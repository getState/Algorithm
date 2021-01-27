#include <iostream>
#include <vector>
using namespace std;
#define MIN -987654321

vector<vector<int>> dp;
int N;
int result = MIN;

void go(int row, int col, int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (col == 0)
        {
            temp += dp[row + i][col + i * 2];
        }
        else
        {
            temp += dp[row + i][col + i * 2] - dp[row + i][col - 1];
        }
    }
    if (result < temp)
    {
        result = temp;
    }
    if (n > 2)
    {
        go(row + 1, col, n - 1);
        go(row + 1, col + 2, n - 1);
    }
}

int main()
{
    int count = 0;
    while (true)
    {
        cin >> N;
        count++;
        if (N == 0)
        {
            return 0;
        }
        result = MIN;
        vector<vector<int>> arr;
        for (int i = 0; i < N; i++)
        {
            vector<int> temp;
            for (int j = 0; j < i * 2 + 1; j++)
            {
                int n;
                cin >> n;
                if (n > result)
                {
                    result = n;
                }
                temp.push_back(n);
            }
            arr.push_back(temp);
        }
        dp = arr;
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j < i * 2 + 1; j++)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
        go(0, 0, N);
        cout << count << ". " << result << endl;
    }
}