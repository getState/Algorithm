#include<iostream>
using namespace std;
int heap[1000000];
int hsize = 0;

void insert(int data){
    int here = ++hsize;
    while(here!=1 && data>heap[here/2]){
        heap[here] = heap[here/2];
        here = here/2;
    }
    heap[here] = data;
}

int deleteHeap(){
    if(hsize==0){
        return 0;
    }
    int result = heap[1];
    heap[1] = heap[hsize--];
    int parent = 1;
    int child;
    while(1){
        child = parent * 2;
        if (child + 1 <= hsize && heap[child] < heap[child+1])
            child++;

        if (child > hsize || heap[child] < heap[parent])
            break;

        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        parent = child;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            int result = deleteHeap();
            cout << result << "\n";
        }
        else
        {
            insert(num);
        }
    }
}