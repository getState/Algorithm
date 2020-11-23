#include <iostream>
// 분할 정복
using namespace std;

long long A, B, C;
long long go(int count)
{
    if (count == 0)
    {
        return 1;
    }
    if (count % 2 == 0)
    {
        return (go(count / 2) * go(count / 2)) % C;
    }
    else
    {
        return (A * go(count - 1)) % C;
    }
}
int main()
{
    cin >> A >> B >> C;
    long long result = go(B);
    cout << result << endl;
}