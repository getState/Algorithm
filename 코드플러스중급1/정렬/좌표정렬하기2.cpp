#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> arr;

bool comparable(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
    {
        return true;
    }
    else if (a.second == b.second)
    {
        if (a.first < b.first)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;

    int a, b;
    while (N--)
    {
        scanf("%d %d", &a, &b);
        arr.push_back(make_pair(a, b));
    }
    sort(arr.begin(), arr.end(), comparable);
    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d %d\n", arr[i].first, arr[i].second);
    }
}