#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
vector<bool> eratosis(4000001, true);
void eratos()
{
    eratosis[0] = false;
    eratosis[1] = false;
    for (int i = 2; i < eratosis.size(); i++)
    {
        if (eratosis[i])
        {
            for (int j = i + i; j < eratosis.size(); j += i)
            {
                eratosis[j] = false;
            }
            arr.push_back(i);
        }
    }
}

int main()
{
    eratos();
    int N;
    cin >> N;
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int result = 0;
    while (right < arr.size())
    {
        if (sum < N)
        {
            right++;
            sum += arr[right];
        }
        else if (sum == N)
        {
            result++;
            sum -= arr[left];
            left++;
            right++;
            sum += arr[right];
        }
        else
        {
            sum -= arr[left++];
        }
    }
    cout << result << endl;
}