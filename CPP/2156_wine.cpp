#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int n;
    scanf("%d",&n);
    int wine[n+1]={0};
    for (int i=1; i<n+1;i++){
        scanf("%d",&wine[i]);
    }
    int dp[n]={0};
    dp[0],wine[0]=0;
    dp[1]=wine[1];
    dp[2]=wine[1]+wine[2];
    for(int i=3;i<n+1;i++) dp[i]=max({dp[i-3]+wine[i-1]+wine[i],dp[i-2]+wine[i],dp[i-1]});

    cout<<dp[n];

    

    return 0;
}