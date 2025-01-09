#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int L,R,C;
char map[30][30][30];
int visited[30][30][30];

int dx[6]={0,0,0,0,1,-1};
int dy[6]={0,0,1,-1,0,0};
int dz[6]={1,-1,0,0,0,0};

int bfs(tuple<int,int,int> start){
    queue<tuple<int,int,int>> q;
    q.push(start);
    visited[get<0>(start)][get<1>(start)][get<2>(start)]=1;
    while(!q.empty()){
        int current_x = get<1>(q.front());
        int current_y = get<2>(q.front());
        int current_z = get<0>(q.front());
        q.pop();
        for(int i=0; i<6; i++){
            int new_x=current_x+dx[i];
            int new_y=current_y+dy[i];
            int new_z=current_z+dz[i];
            if(new_x<0||new_x>=R||new_y<0||new_y>=C||new_z<0||new_z>=L) continue;
            if(visited[new_z][new_x][new_y]=='#' || map[new_z][new_x][new_y]=='#') continue;
            if(visited[new_z][new_x][new_y]==0){
                visited[new_z][new_x][new_y]=visited[current_z][current_x][current_y]+1;
                q.push(make_tuple(new_z,new_x,new_y));
            }
            if(map[new_z][new_x][new_y]=='E'){
                return visited[new_z][new_x][new_y];
            }
        }
    }
    return -1;
}

int main(){
    while(1){
        cin>>L>>R>>C;
        if(L==0 && R==0 && C==0) break;
        for (int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                for(int k=0; k<C; k++){
                    visited[i][j][k]=0;
                }
            }
        }
        string line;
        tuple<int,int,int> start;
        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                cin>>line;
                for(int k=0; k<C; k++){
                    map[i][j][k]=line[k];
                    if(line[k]=='S'){
                        start=make_tuple(i,j,k);
                    }
                }
            }
        }
        int count = bfs(start);
        if(count==-1){
            cout<<"Trapped!"<<"\n";
        }else{
            cout<<"Escaped in "<<count-1<<" minute(s)."<<"\n";
        }
    }

    return 0;
}