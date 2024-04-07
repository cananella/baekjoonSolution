#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N,M;
vector<int> graph[1001];
int entrypoint[1001]={0,};
bool visited[1001]={false,};
vector<int> ans;

void topologySort(){
    queue<int> q;
    for(int i=1;i<=N;i++){
        if (entrypoint[i]) continue;
        q.push(i);
        visited[i]=true;
    }
    while(!q.empty()){
        int cur_node=q.front();
        q.pop();
        ans.push_back(cur_node);
        for(auto& elem:graph[cur_node]){
            if(visited[elem]) continue;
            entrypoint[elem]--;
            if(entrypoint[elem]) continue;
            q.push(elem);
            visited[elem]=true;
        }
    }
    return;
}

int main(){
    cin>>N>>M;
    for(int i=0; i<M;i++){
        int num;
        int before,next;
        cin>>num;
        cin>>before;
        for(int j=0;j<num-1;j++){
            cin>>next;
            graph[before].push_back(next);
            entrypoint[next]++;
            before=next;
        }
    }
    topologySort();
    if(ans.size()==N)for(auto& elem:ans) cout<<elem<<"\n";
    else cout<<0;

    return 0;
}