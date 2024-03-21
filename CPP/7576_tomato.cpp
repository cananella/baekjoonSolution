#include<iostream>
#include<queue>
#include<tuple>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};

int main(){
    int m,n;
    cin>>m>>n;
    queue <tuple<int,int,int>> q;
    int box[n][m];
    bool visited[n][m];
    for (int i=0;i<n;i++) for(int j=0;j<m;j++) visited[i][j]=false;
    int cnt=0;

    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>box[i][j];
            if(box[i][j]==-1)visited[i][j]=true;
            else if(box[i][j]==1){
                visited[i][j]=true;
                q.push(make_tuple(j,i,cnt));   
            }
        }
    }


    int max_cnt=0;
    int last_x,last_y;
    while(!q.empty()){
        int current_x=get<0>(q.front());
        int current_y=get<1>(q.front());
        int current_cnt=get<2>(q.front());
        q.pop();
        // cout<<"current xy "<<current_x<<" "<<current_y<<" "<<current_cnt<<endl;
        int new_x,new_y,new_cnt;
        for(int i=0; i<4; i++){
            new_x = current_x+dx[i];
            new_y = current_y+dy[i];
            new_cnt = current_cnt;
            if(new_x<0||new_y<0||new_x>=m||new_y>=n) continue;
            if(box[new_y][new_x]!=0||visited[new_y][new_x]) continue;
            new_cnt++;
            // cout<<"new xy "<<new_x<<" "<<new_y<<endl;
            q.push(make_tuple(new_x,new_y,new_cnt));
            visited[new_y][new_x]=true;
            if(new_cnt>max_cnt) max_cnt=new_cnt;
            last_x=new_x;
            last_y=new_y;
        }
    }
    visited[last_y][last_x]=true;

    // for (int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<visited[i][j];
    //     }
    //     cout<<endl;
    // }
    
    bool chack= 1;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]) chack=0;
        }
    }
    
    // cout<<max_cnt<<endl;

    if (chack) cout<<max_cnt<<endl;
    else cout<<-1<<endl;
    return 0;
}
