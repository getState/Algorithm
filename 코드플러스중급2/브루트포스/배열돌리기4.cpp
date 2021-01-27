#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

#define MAX 987654321
using namespace std;

int answer = MAX;
void rotate(vector<vector<int>> &arr, tuple<int, int, int> rotateArg)
{
    int r, c, s;
    tie(r, c, s) = rotateArg;
    for (int i = 1; i <= s; i++)
    {
        int now = arr[r - i][c - i]; //마지막에 다시담을 원소
        for (int j = 1; j <= i * 2; j++)
        {
            int next = arr[r - i][c - i + j];
            arr[r - i][c - i + j] = now;
            now = next;
        }
        for (int j = 1; j <= i * 2; j++)
        {
            int next = arr[r - i + j][c + i];
            arr[r - i + j][c + i] = now;
            now = next;
        }
        for (int j = 1; j <= i * 2; j++)
        {
            int next = arr[r + i][c + i - j];
            arr[r + i][c + i - j] = now;
            now = next;
        }
        for (int j = 1; j <= i * 2; j++)
        {
            int next = arr[r + i - j][c - i];
            arr[r + i - j][c - i] = now;
            now = next;
        }
    }
}
void check(vector<vector<int>> arr)
{
    int result = MAX;
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = 0;
        for (int j = 1; j < arr[i].size(); j++)
        {
            temp += arr[i][j];
        }
        if (result > temp)
        {
            result = temp;
        }
    }
    if (answer > result)
    {
        answer = result;
    }
}
int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));
    vector<tuple<int, int, int>> rotateArgs;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < K; i++)
    {
        int r, c, s;
        cin >> r >> c >> s;
        rotateArgs.push_back(make_tuple(r, c, s));
    }
    vector<int> permutations;
    for (int i = 0; i < K; i++)
    {
        permutations.push_back(i);
    }
    do
    {
        vector<vector<int>> temp = arr;
        for (int i = 0; i < K; i++)
        {
            rotate(temp, rotateArgs[permutations[i]]);
        }
        check(temp);

    } while (next_permutation(permutations.begin(), permutations.end()));
    cout << answer << endl;
}