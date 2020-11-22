#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr;
    int N;
    cin>>N;
    int input;
    for(int i = 0 ; i<N ; i++){
        cin>>input;
        arr.push_back(input);
    }
    vector<int> result = arr;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    for(int i = 0 ; i<N ; i++){
        cout<<lower_bound(arr.begin(), arr.end(), result[i]) - arr.begin()<<" ";
    }
    
}