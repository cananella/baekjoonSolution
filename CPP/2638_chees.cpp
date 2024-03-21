#include<iostream>
#include<queue>
using namespace std;

int map[100][100];
bool visited[100][100];
int n,m;
int num_of_chees=0;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void updatemap(){
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) visited[i][j]=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 || i==(n-1) || j==0 || j==(m-1) ){
                if(map[i][j]==0){
                    q.push({j,i});
                    visited[i][j]=true;
                }
            }
        }
    }
    while(!q.empty()){
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx=curx+dx[i];
            int newy=cury+dy[i];
            if(newx<0||newx>=m||newy<0||newy>=n) continue;
            if(visited[newy][newx] || map[newy][newx]==1) continue;
            
            q.push({newx,newy});
            visited[newy][newx]=true;
            map[newy][newx]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&map[i][j]==0) map[i][j]=-1;
        }
    }
}

void cheesMelt(){
    int batch[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++) batch[i][j]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num_of_o2=0;
            if(map[i][j]==1){
                for(int k=0;k<4;k++){
                    int newx=j+dx[k];
                    int newy=i+dy[k];
                    if(newx<0||newx>=m||newy<0||newy>=n) continue;
                    if(map[newy][newx]==0) num_of_o2++;
                }
            }
            if(num_of_o2>=2) {
                batch[i][j]=-1;
                num_of_chees--;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j]+=batch[i][j];
        }
    }
}



int main(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==1) num_of_chees++;
        }
    }

    int time=0;

    while(num_of_chees){
        updatemap();
        cheesMelt();
        time++;
    }

    cout<<time;


    // cout<<"\n";
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }



    return 0;
}