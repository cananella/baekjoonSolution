#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N,M,K;
int candys[30001];
vector<int> relation[30001];
vector<pair<int,int>> groups;
int dp[30001][3000];

void backpack(){
    for(int i=1;i<K;i++){
        for(int j=1;j<groups.size();j++){
            if(groups[j].second>i) dp[j][i]=max(dp[j-1][i],dp[j][i-1]);                     //그룹의 사람수가 i보다 크면 dp태이블의 왼쪽과 위를 비교
            else dp[j][i]=max(dp[j-1][i], dp[j-1][i-groups[j].second] + groups[j].first);   //그룹의 사람수가 i랑 같거나 작으면 dp테이블의 위와 i-그룹의사람수 + 그룹의 사탕수
        }
    }
}
// 그룹번호(사탕수,사람수)-> 1(13,2) 2(26,4) 3(24,2) 4(33,2)
//
// i→\  0  1  2  3  4  5         계산되는 순서
//    0| 0  0  0  0  0  0          1  6       26     
//    1| 0  0 13 13 13 13          2  7       27
//    2| 0  0 13 13 26 26          3  8 ....  28
//    3| 0  0 24 24 37 37          4  9       29
//    4| 0  0 33 33 57 57 <-답     5 10       30
//   ↑그룹번호
//
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>K;
    for(int i=1;i<=N;i++) cin>>candys[i];
    
    for(int i=0;i<M;i++) {
        int a,b;
        cin>>a>>b;
        relation[a].push_back(b);
        relation[b].push_back(a);
    }

    bool flag[N+1]={false,};        //방문 리스트
    groups.push_back({0,0});        //계산편의를위한 의미없는그룹

    for(int i=1;i<=N;i++){          //그룹화 (사탕수,사람수)
        if(flag[i])continue;
        queue<int> q;
        flag[i]=true;
        int sumcandy=candys[i];
        int numOfChild=1;
        for(auto& elem:relation[i]){
            if(flag[elem])continue;
            q.push(elem);
        }
        while(!q.empty()){
            int child = q.front();
            q.pop();
            if(flag[child]) continue;
            flag[child]=true;
            sumcandy+=candys[child];
            numOfChild++;
            for(auto& elem:relation[child]){
                if(flag[elem]) continue;
                q.push(elem);
            }
        }
        if(numOfChild>=K)continue;                      
        groups.push_back({sumcandy,numOfChild});
    }

    for(int i=0;i<K;i++) dp[0][i]=0;
    for(int i=0;i<groups.size();i++) dp[i][0]=0;

    backpack();
    cout<<dp[groups.size()-1][K-1];

    return 0;
}