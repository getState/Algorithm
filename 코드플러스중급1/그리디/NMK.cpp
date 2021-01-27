#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;

int main()
{

    cin >> N >> M >> K;
    if (M + K > N + 1 || N > M * K)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<int> arr;
    for (int i = 1; i <= N; i++)
    {
        arr.push_back(i);
    }
    int check = 1;
    if (M != 1)
    {
        check = (N - K) / (M - 1);
    }
    else
    {
        reverse(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        return 0;
    }
    reverse(arr.begin(), arr.begin() + K);
    if ((N - K) % (M - 1) == 0)
    {
        if (check > K)
        {
            cout << -1 << endl;
            return 0;
        }
    }
    else
    {

        if (check >= K)
        {
            cout << -1 << endl;
            return 0;
        }
        if ((N - K) % (M - 1) + check > K)
        {
            check++;
        }
    }

    for (int i = 0; i < M - 2; i++)
    {
        reverse(arr.begin() + K + check * i, arr.begin() + K + check * (i + 1));
    }
    reverse(arr.begin() + K + check * (M - 2), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}