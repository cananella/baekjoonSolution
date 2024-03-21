#include<iostream>
#include<vector>
#include<tuple>
#include<queue>
#include<algorithm>

using namespace std;

vector<pair<int,int>> axis[3];
vector<tuple<int,int,int>> edge;
int parent[100001];
int n;

int find(int n){
    if(parent[n]==n) return n;
    return parent[n]=find(parent[n]);
}
void unite(int from,int to){
    from=find(from);
    to=find(to);
    if (from<to) parent[to]=from;
    else parent[from]=to;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y,z;
        cin >> x >> y >> z;
        axis[0].push_back({x,i});
        axis[1].push_back({y,i});
        axis[2].push_back({z,i});
    }
    
    sort(axis[0].begin(),axis[0].end());
    sort(axis[1].begin(),axis[1].end());
    sort(axis[2].begin(),axis[2].end());
    for(int i=0;i<n;i++) parent[i]=i;
    for(int i=0;i<n-1;i++){
        edge.push_back({abs(axis[0][i+1].first - axis[0][i].first), axis[0][i].second, axis[0][i+1].second});
        edge.push_back({abs(axis[1][i+1].first - axis[1][i].first), axis[1][i].second, axis[1][i+1].second});
        edge.push_back({abs(axis[2][i+1].first - axis[2][i].first), axis[2][i].second, axis[2][i+1].second});
    }
    sort(edge.begin(),edge.end());

    int cnt=0,ans=0;
    for(auto& elem:edge){
        int cost = get<0>(elem);
        int from = get<1>(elem);
        int to = get<2>(elem);
        if(find(from) !=find(to)){
            unite(from,to);
            ans+=cost;
        }
    }
    cout<<ans;


    return 0;
}