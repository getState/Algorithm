#include <iostream>
#include <map>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<long long, long long> maps;
    long long temp;
    while (N--)
    {
        scanf("%lld", &temp);
        if (maps.find(temp) != maps.end())
        {
            maps[temp]++;
        }
        else
        {
            maps.insert(make_pair(temp, 1));
        }
    }
    map<long long, long long>::iterator iter;
    long long count = -1;
    long long result = -1;
    for (iter = maps.begin(); iter != maps.end(); iter++)
    {
        if (iter->second > count)
        {
            count = iter->second;
            result = iter->first;
        }
        else if (iter->second == count && result > iter->first)
        {
            result = iter->first;
        }
    }
    cout << result << endl;
}