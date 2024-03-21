#include<iostream>
#include<vector>
#include<queue>


using namespace std;
int N,K;
int endNode;

int dp[1001];
int time[1001];
int cnt[1001];
vector<int> edge[1001];


void Craft(){

    queue<int> q;
    for(int root=1;root<=N;root++){
        if(cnt[root]==0) {
            q.push(root);
            dp[root]=time[root];
        }
    }
    for(int i=0;i<N;i++){
        int nowNode=q.front();
        q.pop();
        for(auto& elem:edge[nowNode]){
            int nextNode=elem;
            cnt[nextNode]--;
            dp[nextNode]=max(dp[nextNode],dp[nowNode]+time[nextNode]);
            if(cnt[nextNode]==0)q.push(nextNode);
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>N>>K;
        for(int i=1;i<=N;i++){
            dp[i]=-1;
            cnt[i]=0;
            edge[i].clear();
        }
        for(int i=1;i<=N;i++){
            cin>>time[i];
        }
        for(int i=0;i<K;i++){
            int st,ed;
            cin>>st>>ed;
            edge[st].push_back(ed);
            cnt[ed]++;
        }
        cin>>endNode;
        Craft();
        
        cout<<dp[endNode]<<"\n";
    }
    return 0;
}