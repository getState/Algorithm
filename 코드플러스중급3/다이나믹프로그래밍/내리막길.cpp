#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int row, col;
vector<vector<int>> arr;
vector<vector<int>> dp;

int dnX[] = {0, 0, -1, 1};
int dnY[] = {1, -1, 0, 0};

int go(int nowX, int nowY)
{
    if (dp[nowX][nowY] > 0)
    {
        return dp[nowX][nowY];
    }
    if (nowX == row - 1 && nowY == col - 1)
    {
        return 1;
    }
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextX = nowX + dnX[i];
        int nextY = nowY + dnY[i];
        if (nextX < 0 || nextX >= row || nextY < 0 || nextY >= col)
        {
            continue;
        }
        if (arr[nowX][nowY] > arr[nextX][nextY])
        {
            result += go(nextX, nextY);
        }
    }
    dp[nowX][nowY] = result;
    return result;
}
int main()
{
    cin >> row >> col;
    arr = vector<vector<int>>(row, vector<int>(col, 0));
    dp = vector<vector<int>>(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << go(0, 0) << endl;
}