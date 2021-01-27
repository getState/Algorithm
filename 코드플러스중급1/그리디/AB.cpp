#include <iostream>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    int mid = N / 2;
    int bSize = mid;
    int aSize = N - bSize;
    int maxSize = aSize * bSize;
    if (maxSize < K)
    {
        cout << -1 << endl;
        return 0;
    }
    string result = "";
    for (int i = 0; i < mid; i++)
    {
        result += 'B';
    }
    for (int i = mid; i < N; i++)
    {
        result += 'A';
    }
    int aMax = N - 1;
    int count = 0;
    while (count != K)
    {
        if (K - count >= aSize)
        {
            swap(result[mid - 1], result[aMax]);
            aMax--;
            mid--;
            count += aSize;
        }
        else
        {
            swap(result[mid - 1], result[mid - 1 + K - count]);
            count = K;
        }
    }
    cout << result << endl;
}