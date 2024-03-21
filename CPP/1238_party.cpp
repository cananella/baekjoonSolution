#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

#define INF 1.5e9




using namespace std;
int n,m,x;
vector<pair<int,int>> grape[1001];
vector<pair<int,int>> back_grape[1001];
int comback_dist[1001];
int dist[1001];

void dijkstra(int start, int* dist, vector<pair<int,int>>* grapes){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty()){
        int node=pq.top().second;
        int cost=-pq.top().first;
        pq.pop();
        for(auto& elem:grapes[node]){
            int next_node=elem.first;
            int d=elem.second+cost;
            if(dist[next_node]>d){
                dist[next_node]=d;
                pq.push({-d,next_node});
            }
        }
    }
}



int main(){
    cin>>n>>m>>x;
    for(int i=0;i<m;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        grape[start].push_back({end,cost});
        back_grape[end].push_back({start,cost});
    }

    for(int i=0;i<=n;i++){
        comback_dist[i]=INF;
        dist[i]=INF;
    }


    dijkstra(x,comback_dist,grape);
    dijkstra(x,dist,back_grape);

    int ans=0;
    for(int i =1 ; i<=n ; i++) {
        if(ans<comback_dist[i]+dist[i]) ans=comback_dist[i]+dist[i];
    }

    cout<<ans;
    return 0;
}