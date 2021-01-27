#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int Find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    else
    {
        int y = Find(parent[x]);
        parent[x] = y;
        return y;
    }
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parent[y] = x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n + 1; i++)
    {
        parent.push_back(i);
    }
    while (m--)
    {
        int oper, a, b;
        cin >> oper >> a >> b;
        if (oper == 0)
        {
            Union(a, b);
        }
        else
        {
            if (Find(a) == Find(b))
            {
                cout << "YES"
                     << "\n";
            }
            else
            {
                cout << "NO"
                     << "\n";
            }
        }
    }
    return 0;
}
