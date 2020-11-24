#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> inOrder;
vector<int> postOrder;

void preOrder(int pleft, int pright, int ileft, int iright)
{
    if (pleft > pright || ileft > iright)
    {
        return;
    }
    cout << postOrder[pright] << " ";
    int mid = find(inOrder.begin(), inOrder.end(), postOrder[pright]) - inOrder.begin();
    int leftSize = mid - ileft;
    int rightSize = iright - mid;
    preOrder(pleft, pright - rightSize - 1, ileft, mid - 1);
    preOrder(pleft + leftSize, pright - 1, mid + 1, iright);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    int input;

    for (int i = 0; i < N; i++)
    {
        cin >> input;
        inOrder.push_back(input);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> input;
        postOrder.push_back(input);
    }
    preOrder(0, N - 1, 0, N - 1);
}
