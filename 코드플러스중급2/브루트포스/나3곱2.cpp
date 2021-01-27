#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> result;
vector<long long> arr;
bool check(long long n, int count)
{
    result.push_back(n);
    if (count == arr.size())
    {
        return true;
    }
    long long next1 = -1;
    if (n % 3 == 0)
    {
        next1 = n / 3;
    }
    long long next2 = n * 2;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == next1)
        {
            return check(next1, count + 1);
        }
        else if (arr[i] == next2)
        {
            return check(next2, count + 1);
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    arr = vector<long long>(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (check(arr[i], 1))
        {
            break;
        }
        result.clear();
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
}