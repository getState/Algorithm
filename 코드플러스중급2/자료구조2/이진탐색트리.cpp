#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    multiset<string> mset;
    int N;
    cin >> N;
    string name, oper;
    while (N--)
    {
        cin >> name >> oper;
        if (oper == "enter")
        {
            mset.insert(name);
        }
        else
        {
            mset.erase(name);
        }
    }
    multiset<string>::iterator iter;
    for (iter = mset.rbegin(); iter != mset.rend(); iter++)
    {
        cout << *iter << "\n";
    }
    return 0;
}