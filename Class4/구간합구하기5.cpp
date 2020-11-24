#include <iostream>
using namespace std;
int input[1024][1024] = {
    0,
};
int sumArr[1024][1024] = {
    0,
};
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc;
    cin >> N >> tc;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input[i][j];
            sumArr[i][j] = input[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            sumArr[i][j] += sumArr[i][j - 1];
        }
    }
    int result = 0;
    int x1, y1, x2, y2;
    for (int i = 0; i < tc; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        result = 0;
        x1--;
        x2--;
        y1--;
        y2--;
        for (int j = x1; j <= x2; j++)
        {
            if (y1 == 0)
            {
                result += sumArr[j][y2];
                continue;
            }
            result += sumArr[j][y2] - sumArr[j][y1 - 1];
        }
        cout << result << "\n";
    }
}