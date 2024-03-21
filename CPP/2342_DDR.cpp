#include<iostream>
#include<vector>
#define INF 1e9
#define MAXLEN 100001

using namespace std;

vector<int> order;
int dp[MAXLEN][5][5];
int L_feet_p=0,R_feet_p=0;


int movefeet(int feet_p,int movep){
    int cost=0;
    if (feet_p==0){
        if(movep==1||movep==2||movep==3||movep==4)cost=2;
        else if(movep==0) cost=1;
    }
    else if(feet_p==1||feet_p==3){
        if(movep==2||movep==4)cost=3;
        else if(movep==3) cost=(feet_p==3)?1:4;
        else if(movep==1) cost=(feet_p==1)?1:4;
    }
    else if(feet_p==2||feet_p==4){
        if(movep==1||movep==3)cost=3;
        else if(movep==4) cost=(feet_p==4)?1:4;
        else if(movep==2) cost=(feet_p==2)?1:4;
    }
    return cost;
}

void DP(int cnt){
    if(cnt==order.size()){
        return ;
    }
    int target=order[cnt-1];

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(dp[cnt-1][i][j]==INF)continue;
            if(i==target||j==target) 
                dp[cnt][i][j]=min(dp[cnt][i][j],dp[cnt-1][i][j]+1);
            else{
                dp[cnt][target][j]=min(dp[cnt][target][j],dp[cnt-1][i][j]+movefeet(i,target));
                dp[cnt][i][target]=min(dp[cnt][i][target],dp[cnt-1][i][j]+movefeet(j,target));
            }
        }
    }
    cnt++;
    DP(cnt); 
    return ;
}


int main(){
    int n=1;
    while (n){
        cin>>n;
        order.push_back(n);
    }
    fill_n(&dp[0][0][0],MAXLEN*5*5,INF);
    dp[0][0][0]=0;

    DP(1);
    // for(int k=0;k<order.size();k++){
    //     for(int i=0;i<5;i++){
    //         for(int j=0;j<5;j++){
    //             int temp=(dp[k][i][j]==INF)?0:dp[k][i][j];
    //             cout<<temp<<" ";
    //         }
    //     cout<<" \n";        
    //     }
    //     cout<<"\n\n";
    // }
    int ans=INF;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            ans=min(ans,dp[order.size()-1][i][j]);
        }
    }
    cout<<ans;

    return 0;
}