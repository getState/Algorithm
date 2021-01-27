#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;
set<string> result;

int dnX[] = {-1, 1, 0, 0};
int dnY[] = {0, 0, -1, 1};
vector<vector<int>> arr;

void go(string now, int row, int col)
{
    if (now.size() == 6)
    {
        result.insert(now);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + dnX[i];
        int nextCol = col + dnY[i];
        if (nextRow < 0 || nextRow >= 5 || nextCol < 0 || nextCol >= 5)
        {
            continue;
        }
        go(now + to_string(arr[nextRow][nextCol]), nextRow, nextCol);
    }
}

int main()
{
    for (int i = 0; i < 5; i++)
    {
        vector<int> temp;
        for (int j = 0; j < 5; j++)
        {
            int n;
            cin >> n;
            temp.push_back(n);
        }
        arr.push_back(temp);
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            string s = "";
            s += arr[i][j];
            go(s, i, j);
        }
    }
    cout << result.size() << endl;
}