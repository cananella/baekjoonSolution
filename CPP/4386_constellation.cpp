#include<iostream>
#include<vector>
#include<queue>
#include<cmath>

using namespace std;
int n;
vector<pair<float,float>> stars;
vector<pair<int,float>> grape[100];
int parents[100];
bool visited[100]={false,};

float findCost(pair<float,float> a, pair<float,float> b){
    float r=sqrt(pow(a.first-b.first,2)+pow(a.second-b.second,2));
    return  r;
}

float LST(int start){
    priority_queue<pair<float,int>> pq;
    visited[start]=true;
    for(auto& elem:grape[start]){
        pq.push({-elem.second,elem.first});
    }
    int visitcnt=0;
    float ans=0;
    while(visitcnt!=n-1){
        float cost = -pq.top().first;
        int nextnode = pq.top().second;
        pq.pop();
        if(visited[nextnode]) continue;
        visited[nextnode]=true;
        ans+=cost;
        visitcnt++;
        for(auto& elem:grape[nextnode]){
            if(visited[elem.first])continue;
            pq.push({-elem.second,elem.first});
        }
    }
    return ans;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        float x,y;
        cin>>x>>y;
        stars.push_back({x,y});
        parents[i]=i;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float cost=findCost(stars[i],stars[j]);
            grape[i].push_back({j,cost});
            grape[j].push_back({i,cost});
        }
    }
	cout.setf(std::ios_base::fixed);
	cout.precision(2);
    cout<<LST(0);


    return 0;
}