#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> arr;
vector<int> dp;
int N;

int main()
{
    cin >> N;
    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        arr.push_back(input);
    }
    for (int i = 0; i < N; i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it != dp.end())
        {
            *it = arr[i];
        }
        else
        {
            dp.push_back(arr[i]);
        }
    }
    cout << dp.size() << endl;
}