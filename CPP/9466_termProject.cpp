#include<iostream>
#include<vector>

using namespace std;

int selection[100001];
bool selected[100001]={false,0};
bool visited[100001];
int cnt;

void dfs(int node){
    visited[node]=true;
    int next_node=selection[node];

    if (!visited[next_node]){
        dfs(next_node);
    }
    else if(!selected[next_node]){
        for(int i= next_node; i!=node; i=selection[i]){
            cnt++;
        }
        cnt++;
    }
    selected[node]=true;
    return;
}

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n;
        cin>>n;
        fill_n(selected+1,n*sizeof(bool),false);
        fill_n(visited+1,n*sizeof(bool),false);
        for(int i=1;i<=n;i++){
            cin>>selection[i];
        }
        cnt=0;
        for(int i=1;i<=n;i++){
            if(visited[i])continue;
            dfs(i);
        }
        cout<<n-cnt<<"\n";
    }

    return 0;
}