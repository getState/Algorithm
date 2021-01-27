#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> woods;
int N, M;

long long calc(long long n)
{
    long long result = 0;
    for (int i = 0; i < woods.size(); i++)
    {
        if (woods[i] - n > 0)
        {
            result += woods[i] - n;
        }
    }
    return result;
}

int main()
{
    cin >> N >> M;
    woods = vector<long long>(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> woods[i];
    }
    sort(woods.begin(), woods.end());
    long long left = 0;
    long long right = woods[woods.size() - 1];
    long long mid = (left + right) / 2;
    int result = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (calc(mid) >= M)
        {
            if (result < mid)
            {
                result = mid;
            }
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    cout << result << endl;
}