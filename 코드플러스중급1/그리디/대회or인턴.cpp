#include <iostream>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    int result = 0;
    while (true)
    {
        if (N >= 2 && M >= 1)
        {
            N -= 2;
            M -= 1;
            result++;
        }
        else
        {
            break;
        }
    }
    K -= (N + M);
    if (K > 0)
    {
        result -= K / 3;
        if (K % 3 != 0)
        {
            result -= 1;
        }
    }

    cout << result << endl;
}