#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp(500, vector<int>(500, 0));
vector<pair<int, int>> input;
int go(int start, int end)
{
    if (dp[start][end] > 0)
    {
        return dp[start][end];
    }
    if (end - start == 0)
    {
        return 0;
    }
    if (end - start == 1)
    {
        dp[start][end] = input[start].first * input[start].second * input[end].second;
        return dp[start][end];
    }
    int result = 2100000000;
    for (int i = start; i < end; i++)
    {
        result = min(result, go(start, i) + go(i + 1, end) + input[start].first * input[i].second * input[end].second);
    }
    dp[start][end] = result;
    return dp[start][end];
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int first, second;
        cin >> first >> second;
        input.push_back(make_pair(first, second));
    }
    cout << go(0, N - 1) << endl;
}