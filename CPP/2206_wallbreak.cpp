#include<iostream>
#include<queue>
#include<tuple>
#define INF 1000000;

using namespace std;
int map[1000][1000];
int visited[1000][1000][2];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

void printmap(int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int BFS(int n, int m){
    queue<tuple<int,int,int,bool>> q;
    q.push(make_tuple(0,0,1,true));  // x,y,cost,can break
    visited[0][0][0]=true;

    while(!q.empty()){
        int cur_x=get<0>(q.front());
        int cur_y=get<1>(q.front());
        int cur_cnt=get<2>(q.front());
        bool cur_flag=get<3>(q.front());
        q.pop();
        if(cur_x==m-1&&cur_y==n-1) return cur_cnt;

        for(int i=0;i<4;i++){
            int newx=cur_x+dx[i];
            int newy=cur_y+dy[i];
            int newcnt=cur_cnt+1;
            bool newflag=cur_flag;
            
            if(newx<0||newx>=m||newy<0||newy>=n) continue;
            if(visited[newy][newx][newflag]) continue;
            if(newflag==false && map[newy][newx]==1) continue;
            if(newflag==true && map[newy][newx]==1) newflag=false;
            // cout<<newx<<" "<<newy<<" "<<newcnt<<" "<<newflag<<"\n";
            visited[newy][newx][newflag]=true;
            q.push(make_tuple(newx,newy,newcnt,newflag));
        }
    }
    return -1;
}

int main(){
    int n,m;
    cin>>n>>m;
    string data;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<2;k++) visited[i][j][k]=false;
    for(int i=0;i<n;i++){
        cin>>data;
        for(int j=0;j<m;j++){
            map[i][j]=int(data[j])-48;
        }
    }
    
   

    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++) {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    
    cout<<BFS(n,m);

    return 0;
}