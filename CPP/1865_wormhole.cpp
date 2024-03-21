#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define INF 987654321
using namespace std;
vector<tuple<int,int,int>> edge;
int dist[501]; 

void bellmanFord(int nodeNum){
    dist[1]=0;
    for (int i=0; i<nodeNum;i++){
        for (auto& elem:edge){
            int from = get<0>(elem);
            int to = get<1>(elem);
            int cost = get<2>(elem);
            // cout<<"from: "<<from<<" to: "<<to<<" cost: "<<cost<<"\n";
            // cout<<"dist from "<<dist[from]+cost<<"  dist to "<<dist[to]<<"\n";
            // cout<<"\n";

            if(dist[from]+cost<dist[to]) {
                dist[to]=dist[from]+cost;
                // cout<<"update! \n";
            }
        }
    }
    for(auto& elem:edge){
        int from = get<0>(elem);
        int to = get<1>(elem);
        int cost = get<2>(elem);
        if(dist[from]+cost<dist[to]){
            cout<<"YES\n";
            return;
        }
    }

    cout<<"NO\n";
    return;
}

int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        edge.clear();
        
        int n,m,w;
        scanf("%d %d %d",&n,&m,&w);

        for(int i=1;i<=n;i++) dist[i]=INF;

        int s,e,t;
        for(int j=0; j<m+w;j++){
            scanf("%d %d %d",&s,&e,&t);
            if(j<m){
                edge.push_back(make_tuple(s,e,t));
                edge.push_back(make_tuple(e,s,t));
            }
            else edge.push_back(make_tuple(s,e,-t));
        }
        // for(auto& elem:edge) cout<<get<0>(elem)<<get<1>(elem)<<get<2>(elem)<<"\n";
        bellmanFord(n);
    }
    return 0;
}