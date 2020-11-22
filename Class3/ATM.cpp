#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> arr(N);
    int input;
    for(int i = 0 ; i<N ; i++){
        cin>>input;
        arr[i] = input;
    }
    sort(arr.begin(), arr.end());
    int result = 0;
    for(int i = 0 ; i<N ; i++){
        result += arr[i]*(N-i);
    }
    cout<<result<<endl;
}