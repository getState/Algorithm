#include <iostream>
#include <vector>
using namespace std;

vector<string> arr;
int result = 0;
int N;
long long bitmask = 0;
void change(vector<string> &check, int x, int y)
{
    if (check[x][y] == 'H')
    {
        check[x][y] = 'T';
    }
    else
    {
        check[x][y] = 'H';
    }
}
void reverseCoins(long long bit, vector<string> check)
{
    for (int i = 0; i < N; i++)
    {
        if (bit & (1 << i))
        {
            //i번 비트가 켜져있는지
            for (int j = 0; j < N; j++)
            {
                change(check, i, j);
            }
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        int Hcount = 0;
        for (int j = 0; j < N; j++)
        {
            if (check[j][i] == 'H')
            {
                Hcount++;
            }
        }
        if (Hcount <= N / 2)
        {
            answer += N - Hcount;
        }
        else
        {
            answer += Hcount;
        }
    }
    if (result < answer)
    {
        result = answer;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    arr = vector<string>(N, "");
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (bitmask = 0; bitmask < (1 << N); bitmask++)
    {
        reverseCoins(bitmask, arr);
    }
    cout << N * N - result << endl;
}