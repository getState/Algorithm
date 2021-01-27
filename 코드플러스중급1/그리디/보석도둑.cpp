#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N, K;
vector<pair<int, int>> diamonds;

bool comparable(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;
    int mess, v;
    multiset<int> bags;

    for (int i = 0; i < N; i++)
    {
        cin >> mess >> v;
        diamonds.push_back(make_pair(mess, v));
    }
    for (int i = 0; i < K; i++)
    {
        cin >> mess;
        bags.insert(mess);
    }
    sort(diamonds.begin(), diamonds.end(), comparable);
    long long result = 0;
    cout << *bags.begin() << endl;
    for (int i = 0; i < N; i++)
    {
        auto it = bags.lower_bound(diamonds[i].first);
        if (it != bags.end())
        {
            result += diamonds[i].second;
            bags.erase(it);
        }
    }
    cout << result << endl;
}