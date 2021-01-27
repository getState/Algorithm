#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, S;
    cin >> N >> S;
    vector<int> arr;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        result += temp;
        arr.push_back(temp);
    }
    if (result < S)
    {
        cout << 0 << endl;
        return 0;
    }
    int left = 0;
    int right = 0;
    int sum = arr[0];
    while (left <= right && right < N)
    {
        if (sum >= S)
        {
            if (right - left + 1 < result)
            {
                result = right - left + 1;
            }
            sum -= arr[left];
            left++;
        }
        else
        {
            right++;
            sum += arr[right];
        }
    }
    cout << result << endl;
}