#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,k;
vector<int> backpacklimet;
vector<pair<int,int>> jewel;


long long greedy(){
    long long ans=0;
    int idx=0;
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        while(idx<n && jewel[idx].first<=backpacklimet[i])pq.push(jewel[idx++].second);
        if(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
    }
    return ans;
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int M,V;
        cin>>M>>V;
        jewel.push_back({M,V});
    }
    for(int i=0;i<k;i++){
        int num;
        cin>>num;
        backpacklimet.push_back(num);
    }
    sort(backpacklimet.begin(),backpacklimet.end());
    sort(jewel.begin(),jewel.end());

    cout<<greedy();

    return 0;
}
