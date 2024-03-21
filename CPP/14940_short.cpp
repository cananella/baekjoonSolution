#include <iostream>
#include <queue>
#include <tuple>


using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    int n,m;
    cin>>n>>m;
    int map[n][m];
    int ans[n][m];
    bool visitied[n][m];
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {{visitied[i][j]=false; ans[i][j]=0;}}

    queue <tuple<int,int,int>> q;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>map[i][j];
            if (map[i][j]==2) {
                q.push(make_tuple(j,i,0));
                ans[i][j]=0;
                visitied[i][j]=true;
            }
            if(map[i][j]==0){
                visitied[i][j]=true;
            }
        }
    }
    
    

    while(!q.empty()){
        int cur_x=get<0>(q.front());
        int cur_y=get<1>(q.front());
        int cur_cnt=get<2>(q.front());
        q.pop();
        for (int i=0;i<4;i++){
            int new_x=cur_x+dx[i];
            int new_y=cur_y+dy[i];
            int new_cnt=cur_cnt+1;
            // cout<<"new xycnt "<<new_x<<" "<<new_y<<" "<<new_cnt<<endl;
            if(new_x<0||new_x>=m||new_y<0||new_y>=n)continue;
            if(visitied[new_y][new_x]!=0) continue;
            if(map[new_y][new_x]!=1) continue;
            q.push(make_tuple(new_x,new_y,new_cnt));
            visitied[new_y][new_x]=true;
            ans[new_y][new_x]=new_cnt;
        }
    }

    for (int i=0;i<n;i++) for (int j=0;j<m;j++) if(!visitied[i][j]) ans[i][j]=-1;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    



    return 0;
}