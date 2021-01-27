#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> arr;
int N, C;

int check(int n)
{
    int count = 1;
    int distance = 0;
    int now = arr[0];
    int next;
    for (int i = 1; i < arr.size(); i++)
    {
        int next = arr[i];
        distance = next - now;
        if (distance >= n)
        {
            count++;
            now = arr[i];
        }
    }
    return count;
}

int main()
{
    cin >> N >> C;
    arr = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    int left = 1;

    int result = 0;
    sort(arr.begin(), arr.end());
    int right = arr[arr.size() - 1] - arr[0];
    while (left <= right)
    {
        int mid = (left + right) / 2;

        int ans = check(mid);
        if (ans > C)
        {
            if (result < mid)
            {
                result = mid;
            }
            left = mid + 1;
        }
        else if (ans < C)
        {
            right = mid - 1;
        }
        else
        {
            if (result < mid)
            {
                result = mid;
            }
            left = mid + 1;
        }
    }
    cout << result << endl;
}