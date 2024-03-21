#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int** maze = new int*[n];
    for (int i =0; i<n;i++){
        maze[i]=new int[m];
        fill_n(maze[i],m,0);
        for (int j=0;j<m;j++){
            scanf("%1d",&maze[i][j]);
        }
    }
    queue <tuple<int,int,int>> q;

    int visit[n][m];
    for (int i =0; i<n; i++){
        for (int j =0; j<m; j++){
           visit[i][j]= maze[i][j];
        }
    }
    visit[0][0]=0;

    q.push(make_tuple(0,0,1));
    int h_step=0;
    char temp;
    while (!q.empty()){
        tuple<int,int,int> cur= q.front();
        q.pop();
        for (int i=0; i<4;i++){
            int new_X=get<0>(cur)+dx[i];
            int new_Y=get<1>(cur)+dy[i];
            int step=get<2>(cur);
            if(new_X<0||new_Y<0||new_X>=m||new_Y>=n) continue;
            if(visit[new_Y][new_X]==0) continue;
            visit[new_Y][new_X]=0;
            step++;
            if (new_X==m-1&&new_Y==n-1) h_step=step;
            q.push(make_tuple(new_X,new_Y,step));
            

            //debug
            // for (int i =0; i<n; i++){
            //     for (int j =0; j<m; j++){
            //         cout<<visit[i][j];
            //     }
            // cout<<endl;
            // }
            // cout<<"visit pt  "<<new_X<<new_Y<<step<<endl;
            // cout<<"h_step    "<<h_step<<endl;
            // cout<<"add queue "<<get<0>(q.front())<<get<1>(q.front())<<get<2>(q.front())<<endl;
            // cin>>temp;
        }
    }
    cout<<h_step;
    // for (int i =0; i<n; i++){
    //     for (int j =0; j<m; j++){
    //         cout<<visit[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout<<visit[0][4];

    return 0;
}