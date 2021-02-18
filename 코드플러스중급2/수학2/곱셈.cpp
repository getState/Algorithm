#include <iostream>
#include <vector>
using namespace std;

long long calc(int a, int b, int c)
{
    if (b == 0)
    {
        return 1;
    }
    else if (b == 1)
    {
        return a % c;
    }
    else if (b % 2 == 1)
    {
        return (a * calc(a, b - 1, c)) % c;
    }
    else
    {
        long long x = calc(a, b / 2, c) % c;
        return (x * x) % c;
    }
}

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    cout << calc(a, b, c);
    return 0;
}