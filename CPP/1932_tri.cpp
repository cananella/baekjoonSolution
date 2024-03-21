#include <iostream>

using namespace std;

int main(){
    int n;
    int tri[501][501]={0};
    int sum_tri[501][501]={0};
    scanf("%d",&n);
    for(int i=1; i<=n;i++){
        for(int j=1; j<=i;j++){
            scanf("%d",&tri[i][j]);
        }
    }

    sum_tri[1][1]=tri[1][1];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            sum_tri[i][j]=max(sum_tri[i-1][j],sum_tri[i-1][j-1])+tri[i][j];
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++) if(ans<sum_tri[n][i])ans=sum_tri[n][i];
    cout<< ans;
    
    return 0;
}