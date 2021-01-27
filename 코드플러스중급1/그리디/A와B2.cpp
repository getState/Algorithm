#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

string S, T;

int main()
{
    cin >> S >> T;

    vector<string> arr;
    queue<string> que;
    que.push(T);
    while (!que.empty())
    {
        string temp = que.front();
        que.pop();
        if (temp.size() == S.size())
        {
            if (temp == S)
            {
                cout << 1 << endl;
                return 0;
            }
            else
            {
                continue;
            }
        }
        if (temp[0] == 'A' && temp[temp.size() - 1] == 'A')
        {
            que.push(temp.substr(0, temp.size() - 1));
        }
        else if (temp[0] == 'A' && temp[temp.size() - 1] == 'B')
        {
            continue;
        }
        else if (temp[0] == 'B' && temp[temp.size() - 1] == 'A')
        {
            que.push(temp.substr(0, temp.size() - 1));
            string reverseTemp = temp;
            reverse(reverseTemp.begin(), reverseTemp.end());
            que.push(reverseTemp.substr(0, reverseTemp.size() - 1));
        }
        else
        {
            string reverseTemp = temp;
            reverse(reverseTemp.begin(), reverseTemp.end());
            que.push(reverseTemp.substr(0, reverseTemp.size() - 1));
        }
    }
    cout << 0 << endl;
}