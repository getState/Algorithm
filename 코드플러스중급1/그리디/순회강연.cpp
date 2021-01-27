#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N;
vector<pair<int, int>> arr;
vector<bool> days(10001, false);

bool comparable(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int d, p;
    int maxDay = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> p >> d;
        arr.push_back(make_pair(d, p));
        if (d > maxDay)
        {
            maxDay = d;
        }
    }
    sort(arr.begin(), arr.end(), comparable);
    int cnt = 1;
    int result = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int day = arr[i].first;
        int consume = arr[i].second;
        for (int j = day; j >= 1; j--)
        {
            if (days[j] == false)
            {
                days[j] = true;
                result += consume;
                break;
            }
        }
    }
    cout << result << endl;
}