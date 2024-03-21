#include<iostream>
#include<tuple>
#include<queue>
#include<algorithm>
#include<vector>
#define INF 2e8

using namespace std;
int n;

vector<pair<int,int>> grape[1001];

int dist[1001];
int route[1001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    dist[start]=0;
    while(!pq.empty()){
        int d= -pq.top().first;
        int node=pq.top().second;
        pq.pop();
        if(dist[node]<d) continue;
        for(auto& elem:grape[node]){
            int cost =d+elem.second;
            if(cost<dist[elem.first]){
                dist[elem.first] = cost;
                route[elem.first] = node;
                pq.push(make_pair(-cost,elem.first));
            }
        }
    }
}

int main(){
    int m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int start,end,cost;
        cin>>start>>end>>cost;
        grape[start].push_back({end,cost});
    }

    for(int i=1;i<=n;i++) {
        dist[i]=INF;
        route[i]=0;
    }

    int st,en;
    cin>>st>>en;
    
    dijkstra(st);
    vector<int> ans;
    int idx=en;
    while(1){
        if(route[idx]==0){
            ans.push_back(idx);
            break;
        }
        ans.push_back(idx);
        idx=route[idx]; 
    }
    reverse(ans.begin(),ans.end());

    cout<<dist[en]<<"\n";
    cout<<ans.size()<<"\n";
    for(auto& elem:ans) cout<<elem<<" ";



    return 0;
}