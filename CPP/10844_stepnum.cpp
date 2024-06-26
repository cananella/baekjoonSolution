#include<iostream>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int count=0;
    int dp[101][10]={0};

    dp[1][0]=0;
    for (int i=1;i<10;i++) dp[1][i]=1;
    for(int i=2; i<n+1;i++){
        for (int j=0;j<10;j++){
            if (j==0) dp[i][j]=dp[i-1][1]%1000000000;
            else if(j==9) dp[i][j]=dp[i-1][8]%1000000000;
            else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1])%1000000000;            
        }

    }
    long long ans=0;
    for(int i=0; i<10;i++)ans+=dp[n][i];
    cout<<ans%1000000000<<endl;
    

    return 0;
}