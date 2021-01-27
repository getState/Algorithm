#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fail;
vector<int> preprocessing(string p)
{
    int m = p.size();
    vector<int> pi(m, 0);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j > 0 && p[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (p[i] == p[j])
        {
            pi[i] = j + 1;
            j += 1;
        }
        else
        {
            pi[i] = 0;
        }
    }
    return pi;
}
vector<int> KMP(string s, string p)
{
    vector<int> pi = preprocessing(p);
    vector<int> ans;
    int n = s.size();
    int m = p.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j > 0 && s[i] != p[j])
        {
            j = pi[j - 1];
        }
        if (s[i] == p[j])
        {
            if (j == m - 1)
            {
                ans.push_back(i - m + 1);
                j = pi[j];
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    string S, P;
    getline(cin, S);
    getline(cin, P);
    if (S.size() < P.size())
    {
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans = KMP(S, P);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}