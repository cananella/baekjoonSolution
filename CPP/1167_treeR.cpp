#include<iostream>
#include<vector>
using namespace std;

int max_dist=0,max_node;

void dfs(int x,int dist ,vector <pair<int,int>>* nodes,pair<bool,int>* visit){
    if(visit[x].first) return;
    visit[x].first=true;
    visit[x].second=dist;
    if(max_dist<dist){
        max_dist=dist;
        max_node=x;
    }
    for(int i=0; i<nodes[x].size(); i++){
        int a=nodes[x][i].first;
        int b=nodes[x][i].second;
        if(visit[a].first)continue;
        dfs(a,dist+b,nodes,visit);
    }
}


int main(){

    int v;
    cin>>v;
    vector <pair<int,int>> nodes[v+1];
    pair<bool,int> visit[v+1];
    for(int i=0; i<v;i++){
        int num;
        cin>>num;
        int s1,s2;
        cin>>s1;
        while(s1!=-1){
            cin>>s2;
            nodes[num].push_back(make_pair(s1,s2));
            cin>>s1;
        }
    }

    for(auto& elem:visit) elem=make_pair(false,0);
    dfs(1,0,nodes,visit);
    for(auto& elem:visit) elem=make_pair(false,0);
    max_dist=0;
    dfs(max_node,0,nodes,visit);

    cout<<max_dist;
    
    // for(auto& elem:visit){
    //     cout<<elem.second<<" ";
    // }


    // for(auto& node:nodes){
    //     for(auto& list:node){
    //         cout<<list.first<<"-"<<list.second<<"  ";
    //     }
    //     cout<<endl;
    // }



    return 0;
}