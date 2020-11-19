#include <iostream>
using namespace std;

struct heap
{
    int arr[100000];
    int size = 0;
};

void insert(heap *hp, int data)
{
    int here = ++hp->size;

    while ((here != 1) && (data < hp->arr[here / 2]))
    {
        hp->arr[here] = hp->arr[here / 2];
        here /= 2;
    }
    hp->arr[here] = data;
}
int deleteData(heap *hp)
{
    if (hp->size == 0)
        return 0;
    int ret = hp->arr[1];
    hp->arr[1] = hp->arr[hp->size--];
    int parent = 1;
    int child;

    while (1)
    {
        child = parent * 2;
        if (child + 1 <= hp->size && hp->arr[child] > hp->arr[child + 1])
            child++;

        if (child > hp->size || hp->arr[child] > hp->arr[parent])
            break;

        int temp = hp->arr[parent];
        hp->arr[parent] = hp->arr[child];
        hp->arr[child] = temp;
        parent = child;
    }

    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    struct heap hp;
    while (n--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            int result = deleteData(&hp);
            cout << result << "\n";
        }
        else
        {
            insert(&hp, num);
        }
    }
}