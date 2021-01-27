#include <iostream>
#include <vector>

using namespace std;

int dX[] = {0, -1, 1};

int main()
{
    int N;
    cin >> N;
    vector<int> input;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        input.push_back(a);
    }
    vector<vector<int>> arr;
    vector<int> result;
    for (int i = 0; i < 3; i++)
    {
        vector<int> temp(2);
        int count = 0;

        temp[0] = (input[0] + dX[i]);
        for (int j = 0; j < 3; j++)
        {
            if (i == 0 && j == 0)
            {
                count = 0;
            }
            else if (i != 0 && j != 0)
            {
                count = 2;
            }
            else
            {
                count = 1;
            }
            temp[1] = (input[1] + dX[j]);
            result.push_back(count);
            arr.push_back(temp);
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        int distance = arr[i][1] - arr[i][0];
        for (int j = 2; j < input.size(); j++)
        {
            int nextDst = input[j] - arr[i][j - 1];
            if (distance == nextDst)
            {
                arr[i].push_back(input[j]);
            }
            else if (abs(distance - nextDst) == 1)
            {
                if (distance > nextDst)
                {
                    arr[i].push_back(input[j] + 1);
                }
                else
                {
                    arr[i].push_back(input[j] - 1);
                }
                result[i]++;
            }
            else
            {
                result[i] = -1;
                break;
            }
        }
    }
    int answer = 10000000;
    for (int i = 0; i < arr.size(); i++)
    {
        if (result[i] == -1)
        {
            continue;
        }
        else
        {
            if (answer > result[i])
            {
                answer = result[i];
            }
        }
    }
    if (answer == 10000000)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << answer << endl;
    }
}