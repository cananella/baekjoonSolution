#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;
bool visited_dfs[1001];
bool visited_bfs[1001];

void dfs(int x , vector<int> *graph){
    visited_dfs[x]=true;
    cout<<x<<" ";
    for(int i=0; i<graph[x].size();i++){
        int y= graph[x][i];
        if(!visited_dfs[y]) dfs(y,graph);
    }
}

void bfs(int x, vector<int> *graph){
    queue<int> q;
    q.push(x);
    visited_bfs[x]=true;
    while(!q.empty()){
        int y=q.front();
        q.pop();
        cout<<y<<" ";
        for (int i=0;i<graph[y].size();i++){
            int z= graph[y][i];
            if(!visited_bfs[z]){
                q.push(z);
                visited_bfs[z]=true;
            }
            
        }
    }
}


int main(){
    int n,m,v;
    cin>>n>>m>>v;
    vector<int> graph[n+1];

    for (int i=1; i<=m;i++){
        int s , e;
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for (int i=1; i<=n;i++){
        sort(graph[i].begin(),graph[i].end());
    }
    
    dfs(v,graph);
    cout<<endl;
    bfs(v,graph);


    return 0;
}