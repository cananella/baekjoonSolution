#include<iostream>
#include<set>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int re=0; re<n;re++){
        int t=0;
        cin>>t;
        multiset <int> ms;
        while(t--){
            char func;
            int num;
            cin>>func>>num;
            if(func=='I'){
                ms.insert(num);
            }
            else{
                if(ms.empty()) continue;
                else if(num==1){
                    auto iter= ms.end();
                    iter--;
                    ms.erase(iter);
                }
                else{
                    ms.erase(ms.begin());
                }
            }
        }
        // for(set<int>::iterator i=ms.begin(); i!=ms.end();i++){
        //     cout<<*i<<" ";
        // }
        // cout<<endl;

        if(ms.empty()) cout<<"EMPTY"<<endl;
        else { 
            auto end_iter=ms.end();
            end_iter--;
            cout<<*end_iter<<' '<<*ms.begin()<<endl;
        }
    }

    return 0;
}