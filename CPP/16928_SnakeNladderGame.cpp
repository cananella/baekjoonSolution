#include<iostream>
#include<queue>

using namespace std;

bool visited[101];


int main(){
    int n,m;
    cin>>n>>m;
    pair<int,int> ladderNsnake[n+m];

    for (int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ladderNsnake[i]=make_pair(a,b);
    }

    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ladderNsnake[n+i]=make_pair(a,b);
    }
    fill(visited,visited+sizeof(visited),false);
    queue <pair<int,int>> q;
    q.push(make_pair(1,0));
    visited[1]=true;
    bool flag=true;
    while (!q.empty()&&flag){
        int cur_p=q.front().first;
        int cur_cnt=q.front().second;
        q.pop();
        int new_p,new_cnt;

        for (int i=1;i<7;i++){
            new_p=cur_p+i;
            new_cnt=cur_cnt;
            for(int j=0;j<m+n;j++){
                if(ladderNsnake[j].first==new_p) {
                    new_p=ladderNsnake[j].second;
                    // cout<<"ladderNsnack " <<ladderNsnake[j].first <<" "<<new_p<<endl;
                    }
            }
            if(new_p>100)continue;
            if(visited[new_p])continue;
            new_cnt++;
            if(new_p==100){
                cout<<new_cnt;
                flag=false;
                while(!q.empty()) q.pop();
            }
            q.push(make_pair(new_p,new_cnt));
            // cout<<"curp->newp cnt " <<cur_p <<" "<<new_p<<" "<<new_cnt<<endl;
            visited[new_p]=true;
            
        }
        
    }
    

    return 0;
}