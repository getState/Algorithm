#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string S, T;
    cin >> S >> T;
    string result;
    for (int i = T.size() - 1; i >= S.size(); i--)
    {
        if (T[i] == 'B')
        {
            result = T.substr(0, i);
            reverse(result.begin(), result.end());
            T = result + T.substr(i);
        }
    }
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != T[i])
        {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}