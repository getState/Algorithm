#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> arr(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    stack<int> stk;
    long long ans = 0;
    for (int i = 0; i < N; i++)
    {
        int num = arr[i];
        while (!stk.empty() && arr[stk.top()] <= arr[i])
        {
            ans++;
            stk.pop();
            int width = i;
        }
        stk.push(num);
    }
}