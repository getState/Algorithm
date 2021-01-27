#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

int calc(int n)
{
    int result = 0;
    for (int start = 1, len = 1; start <= n; start *= 10, len++)
    {
        int end = start * 10 - 1;
        if (end > n)
        {
            end = n;
        }
        result += (end - start + 1) * len;
    }
    return result;
}

int main()
{
    int N, K;
    cin >> N >> K;
    if (calc(N) < K)
    {
        cout << -1 << endl;
        return 0;
    }
    int left = 1;
    int right = N;
    int ans = 0;
    while (left < right)
    {
        int mid = (left + right) / 2;
        long long len = calc(mid);
        if (len > K)
        {
            right = mid;
        }
        else if (len < K)
        {
            left = mid + 1;
        }
        else
        {
            cout << mid % 10 << endl;
            return 0;
        }
    }
    int count = K - calc(left - 1);
    string s = to_string(left);
    cout << s[count - 1] << endl;
}