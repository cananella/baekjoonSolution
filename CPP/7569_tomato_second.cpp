#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,-1,0,1,0,0};
int dz[6]={0,0,0,0,1,-1};

int main(){
    int m,n,h;
    cin>>m>>n>>h;
    queue <tuple<int,int,int,int>> q;
    int box[n][m][h];
    bool visited[n][m][h];
    for (int k=0;k<h;k++) for (int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j][k]=false;
    int cnt=0;

    for (int k=0;k<h;k++){
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>box[i][j][k];
                if(box[i][j][k]==-1)visited[i][j][k]=true;
                else if(box[i][j][k]==1){
                    visited[i][j][k]=true;
                    q.push(make_tuple(j,i,k,cnt));   
                }
            }
        }
    }


    int max_cnt=0;
    int last_x,last_y,last_z;

    while(!q.empty()){
        int current_x=get<0>(q.front());
        int current_y=get<1>(q.front());
        int current_z=get<2>(q.front());
        int current_cnt=get<3>(q.front());
        q.pop();
        // cout<<"current xyz "<<current_x<<" "<<current_y<<" "<<current_z<<" "<<current_cnt<<endl;
        int new_x,new_y,new_z,new_cnt;
        for(int i=0; i<6; i++){
            new_x = current_x+dx[i];
            new_y = current_y+dy[i];
            new_z = current_z+dz[i];
            new_cnt = current_cnt;
            if(new_x<0||new_y<0||new_z<0||new_x>=m||new_y>=n||new_z>=h) continue;
            if(box[new_y][new_x][new_z]==1||box[new_y][new_x][new_z]==-1||visited[new_y][new_x][new_z]) continue;
            new_cnt++;
            // cout<<"new xy "<<new_x<<" "<<new_y<<" "<<new_z<<endl;
            q.push(make_tuple(new_x,new_y,new_z,new_cnt));
            visited[new_y][new_x][new_z]=true;
            if(new_cnt>max_cnt) max_cnt=new_cnt;

        }
    }

    // cout<<"d"<<endl;
    // for (int k=0;k<h;k++){
    //     for (int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             cout<<visited[i][j][k];
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    
    bool chack= 1;
    for (int k=0;k<h;k++){
        for (int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j][k]) chack=0;
            }
        }
    }


    if (chack) cout<<max_cnt<<endl;
    else cout<<-1<<endl;
    return 0;

}
