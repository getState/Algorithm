#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, L, R, X;
vector<int> arr;
int result = 0;

void go(int start, int end, int sum)
{
    if (start == end)
    {
        if (sum >= L && sum <= R)
        {
            result++;
        }
        return;
    }
    if (sum > R)
    {
        return;
    }
    go(start + 1, end, sum);
    go(start + 1, end, sum + arr[start + 1]);
}

int main()
{
    cin >> N >> L >> R >> X;
    arr = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int start = arr[i];
            int end = arr[j];
            int sum = start + end;
            if (end - start >= X && sum <= R)
            {
                go(i, j - 1, sum);
            }
        }
    }
    cout << result << endl;
}