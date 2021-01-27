#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> arr;

long long calc(long long n)
{
    long long result = 0;
    for (long long i = 0; i < arr.size(); i++)
    {
        result += arr[i] / n;
    }
    return result;
}
int main()
{
    int N, K;
    cin >> N >> K;
    arr = vector<long long>(N, 0);
    for (long long i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    long long left = 1;
    sort(arr.begin(), arr.end());
    long long right = arr[arr.size() - 1];
    long long result = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        long long temp = calc(mid);
        if (temp >= K)
        {
            result = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result << endl;
}