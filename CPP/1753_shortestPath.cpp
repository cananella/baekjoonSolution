#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
int v,e,num;
vector<pair<int,int>> graph[20001];
int length[20001];

void dijkstra(int start){
    priority_queue<pair<int,int>> pq;

    pq.push({0,start}); //  <cost,node>
    length[start]=0;
    while(!pq.empty()){
        int dist = -pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(length[now]<dist) continue;
        for(auto& elem:graph[now]){
            int cost= dist+elem.second;
            if(cost<length[elem.first]){
                length[elem.first]=cost;
                pq.push(make_pair(-cost,elem.first));
            }
        }        
    }
}

int main(){
    scanf("%d %d",&v, &e);
    scanf("%d",&num);
    for(int i=0;i<e;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u].push_back(make_pair(v,w));
    }
    fill(length,length+20001,INF);
    dijkstra(num);

    for(int i=1;i<=v;i++){
        if(length[i]==INF) printf("INF\n");
        else printf("%d\n",length[i]);
    }
}