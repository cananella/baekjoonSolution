#include<iostream>
#include<vector>
#include<cstring>


using namespace std;
bool visit[100];
vector<int> v[100];

void DFS(int x){
    for(int i=0;i<v[x].size();i++){
        if (!visit[v[x][i]]){
            visit[v[x][i]]=true;
            DFS(v[x][i]);
        } 
    }
}


int main(){

    int n;
    cin>>n;
    int num;
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>num;
            if (num) v[i].push_back(j);
        }
    }
    // for (int i=0;i<n;i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    

    for (int i=0;i<n;i++){
        memset(visit,0,sizeof(visit));
        DFS(i);
        for(int j=0;j<n;j++) cout<<visit[j]<<" ";
        cout<<endl;
    }
    
    return 0;
}