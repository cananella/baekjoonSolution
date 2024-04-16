#include<iostream>

using namespace std;
int n;
int list [1000]={0,};
int dp [1000]={1,};

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>> list[i];
        dp[i]=1;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(list[j]<list[i]) dp[i]=max(dp[i],dp[j]+1);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,dp[i]);
    }
    cout<<ans;


    return 0;
}