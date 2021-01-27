#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

vector<pair<int, int>> arr;

bool comparable(pair<int, int> a, pair<int, int> b)
{
    int size1 = a.first * a.second;
    int size2 = b.first * b.second;
    if (size1 >= size2)
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
    int H, W;
    cin >> H >> W;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int row, col;
        cin >> row >> col;
        arr.push_back(make_pair(row, col));
    }
    int result = 0;
    sort(arr.begin(), arr.end(), comparable);
    for (int i = 0; i < arr.size(); i++)
    {
        int row1 = arr[i].first;
        int col1 = arr[i].second;
        for (int j = i + 1; j < arr.size(); j++)
        {
            int row2 = arr[j].first;
            int col2 = arr[j].second;
            if (col1 + col2 <= W && max(row1, row2) <= H)
            {
                result = max(result, row1 * col1 + row2 * col2);
            }
            else if (max(col1, col2) <= W && row1 + row2 <= H)
            {
                result = max(result, row1 * col1 + row2 * col2);
            }
        }
    }
    cout << result << endl;
}