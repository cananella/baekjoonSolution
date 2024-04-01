#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int n,m;
int entry[32001]={0,};
vector<int> graph[32001];

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        entry[b]++;
        graph[a].push_back(b);
    }

    priority_queue<int> pq;
    for(int i=1;i<=n;i++) if(entry[i]==0) pq.push(-i);

    while(!pq.empty()){
        int quizNum= -pq.top();
        pq.pop();
        for(auto& elem:graph[quizNum]){
            entry[elem]--;
            if(entry[elem]==0) pq.push(-elem);
        }
        cout<< quizNum<<" ";
    }

    return 0;
}