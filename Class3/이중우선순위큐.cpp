#include<iostream>
#include<set>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int testCase;
    cin>>testCase;
    while(testCase--){
        multiset<int> mset;
        int n;
        cin>>n;
        while(n--){
            char x;
            int num;
            cin>>x>>num;
            if(x=='I'){
                mset.insert(num);
            }else{
                if(mset.empty()){
                    continue;
                }
                if(num==1){
                    // 최대값
                    mset.erase(--mset.end());
                }else{
                    // 최소값
                    mset.erase(mset.begin());
                }
            }
        }

        if(mset.empty()){
            cout<<"EMPTY"<<endl;
        }else{
            cout<<*(--mset.end())<<" "<<*mset.begin()<<endl;
        }
    }
}