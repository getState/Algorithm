#include <iostream>
#include <vector>

using namespace std;

int N;
long long M;
vector<vector<int>> calc(vector<vector<int>> a, vector<vector<int>> b)
{
    vector<vector<int>> result(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] = result[i][j] % 1000;
        }
    }
    return result;
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> arr(N, vector<int>(N, 0));
    vector<vector<int>> ans(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {

        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
        ans[i][i] = 1;
    }

    while (M > 0)
    {
        if (M % 2 == 1)
        {
            ans = calc(ans, arr);
        }
        arr = calc(arr, arr);
        M /= 2;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << ans[i][j] % 1000 << ' ';
        }
        cout << "\n";
    }
    return 0;
}