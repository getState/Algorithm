#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr(10001, 0);
    int N;
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        arr[temp]++;
    }
    for (int i = 1; i < 10001; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("%d\n", i);
        }
    }
}