#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct time{
    int begin;
    int end;
};
bool cmp(time t1, time t2){
    if(t1.end==t2.end){
        return t1.begin<t2.begin;
    }else{
        return t1.end<t2.end;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<time> arr;
    int n;
    int begin;
    int end;
    int result = 0;
    int now = 0;
    cin>>n;
    time temp;
    while(n--){
        cin>>begin>>end;
        temp.begin = begin;
        temp.end = end;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i = 0 ; i<arr.size() ; i++){
        if(now<=arr[i].begin){
            now = arr[i].end;
            result++;
        }
    }
    cout<<result<<endl;
}