#include<iostream>
#include<queue>
#include<tuple>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    int nom_cnt,odd_cnt;
    int n;
    cin>>n;
    char pic[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin>>pic[i][j];
        }
    }
    
    // for (int i=0;i<n;i++){
    //     for (int j=0;j<n;j++){
    //         cout<<pic[i][j];
    //     }
    //     cout<<endl;
    // }    
    bool visited[n][n];
    for (int i=0;i<n;i++)for (int j=0;j<n;j++) visited[i][j]=false;
    
    queue<tuple<int,int,char>> q;
    int cnt=0;
    int cntflag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                q.push(make_tuple(j,i,pic[i][j]));  
                visited[i][j]=true;
                cntflag=true;
            }
            while(!q.empty()){
                int cur_x=get<0>(q.front());
                int cur_y=get<1>(q.front());
                char cur_c=get<2>(q.front());
                // cout<< "cur x "<<cur_x<<"  cur y "<<cur_y<<"  cur c "<<cur_c<<"  cnt "<<cnt<<endl;
                q.pop();
                int new_x,new_y;
                char new_c;
                for(int k=0;k<4;k++){
                    
                    new_x=cur_x+dx[k];
                    new_y=cur_y+dy[k];
                    if(new_x<0||new_x>=n||new_y<0||new_y>=n) continue;
                    if(visited[new_y][new_x]) continue;
                    new_c=pic[new_y][new_x];
                    // cout<<"newxy "<<new_x<<" "<<new_y<< " newc "<<new_c<<endl;
                    if(new_c!=cur_c)  continue; 
                    visited[new_y][new_x]=true;
                    q.push(make_tuple(new_x,new_y,new_c));
                }
            }
            if(cntflag){
                cntflag=false;
                cnt++;
            }
        }
    }
    nom_cnt=cnt;
    for (int i=0;i<n;i++)for (int j=0;j<n;j++) visited[i][j]=false;
    cnt=0;
    cntflag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                q.push(make_tuple(j,i,pic[i][j]));  
                visited[i][j]=true;
                cntflag=true;
            }
            while(!q.empty()){
                int cur_x=get<0>(q.front());
                int cur_y=get<1>(q.front());
                char cur_c=get<2>(q.front());
                // cout<< "cur x "<<cur_x<<"  cur y "<<cur_y<<"  cur c "<<cur_c<<endl;
                q.pop();
                int new_x,new_y;
                char new_c;
                for(int k=0;k<4;k++){
                    new_x=cur_x+dx[k];
                    new_y=cur_y+dy[k];
                    if(new_x<0||new_x>=n||new_y<0||new_y>=n) continue;
                    if(visited[new_y][new_x]) continue;
                    new_c=pic[new_y][new_x];
                    if(new_c!=cur_c) if(new_c=='B'||cur_c=='B')  continue;
                    visited[new_y][new_x]=true;
                    q.push(make_tuple(new_x,new_y,new_c));
                }
            }
            if(cntflag){
                cntflag=false;
                cnt++;
            }
        }
    }
    odd_cnt=cnt;
    cout<<nom_cnt<<' '<<odd_cnt;


    return 0;
}