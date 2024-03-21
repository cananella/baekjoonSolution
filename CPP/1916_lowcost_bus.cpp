#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<tuple>
#define INF 2e9
using namespace std;

vector<pair<int,int>> nodes[1001];
int d[1001];
int n;

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;
    pq.push({0,start});
    d[start]=0;
    while(!pq.empty()){
        int dist= -pq.top().first;
        int now_n = pq.top().second;
        pq.pop();
        if(d[now_n]<dist) continue;
        for(auto& elem:nodes[now_n]){
            int cost = dist+elem.second;
            if(cost<d[elem.first]){
                d[elem.first]=cost;
                pq.push(make_pair(-cost,elem.first));
            }
        }
    }
}


int main(){
    int m;
    cin>>n>>m;
    while(m--){
        int start,end,cost;
        cin>>start>>end>>cost;
        nodes[start].push_back({end,cost});
    }
    for(int i=1;i<=n;i++) d[i]=INF;
    int st,en;
    cin>>st>>en;

    dijkstra(st);
    cout<<d[en];

    return 0;
}
