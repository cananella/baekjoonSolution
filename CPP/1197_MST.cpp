#include<iostream>
#include<queue>
#include<vector>

using namespace std;
int v,e;
vector<pair<int,int>> grape[10001];


int MST(){
    int ans=0;
    bool visit[10001]={false,};
    priority_queue<pair<int,int>> pq;
    pq.push({-0,1});
    while(!pq.empty()){
        int node = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(visit[node]) continue;
        ans+=cost;
        visit[node]=true;
        for(auto& elem:grape[node]){
            int next_node=elem.first;
            int next_cost=elem.second;
            pq.push({-next_cost,next_node});
        }
    }
    return ans;
}

int main(){
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        grape[a].push_back({b,c});
        grape[b].push_back({a,c});
    }

    cout<<MST();

    return 0;
}