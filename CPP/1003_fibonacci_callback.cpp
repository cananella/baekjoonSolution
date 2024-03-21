#include<iostream>

using namespace std;

int main(){

    int t,n;
    pair<int,int> DP[41];
    cin>>t;

    DP[0]= make_pair(1,0);
    DP[1]= make_pair(0,1);

    for (int i=2;i<41;i++){
        int f=DP[i-1].first+DP[i-2].first;
        int s=DP[i-1].second+DP[i-2].second;
        DP[i]=make_pair(f,s);
    }

    for (int i=0;i<t;i++){
        cin>>n;
        cout<<DP[n].first<<" "<<DP[n].second<<endl;
    }



    return 0;
}