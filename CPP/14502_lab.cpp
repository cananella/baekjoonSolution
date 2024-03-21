#include<iostream>
#include<queue>
#include<vector>
#include<tuple>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
    int n,m;
    cin >>n>>m;
    int map[8][8];
    
    vector<tuple<int,int,int,int,int,int>> wall;
    

    for(int i=0; i<n; i++){
        for(int j=0;j<m; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            for(int k=0;k<n;k++){
                for(int l=0;l<m;l++){

                    for(int o=0;o<n;o++){
                        for(int p=0;p<m;p++){

                            if((i==k&&j==l)||(i==o&&j==p)||(k==o&&l==p))continue;
                            if(map[i][j]==0 && map[k][l]==0 && map[o][p]==0) wall.push_back(make_tuple(j,i,l,k,p,o));
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(auto& elem:wall){
        queue<pair<int,int>> virus;
        bool visited[n][m];
        for(int i=0; i<n; i++) for(int j=0;j<m; j++) visited[i][j]=false;
        for(int i=0; i<n; i++){
            for(int j=0;j<m; j++){
                if(map[i][j]==1) visited[i][j]=true;
                else if(map[i][j]==2) {
                    virus.push({j,i});
                    visited[i][j]=true;
                }
            }
        }
        visited[get<1>(elem)][get<0>(elem)]=true;
        visited[get<3>(elem)][get<2>(elem)]=true;
        visited[get<5>(elem)][get<4>(elem)]=true;
        while(!virus.empty()){
            int cur_x=virus.front().first;
            int cur_y=virus.front().second;
            virus.pop();
            for(int i=0; i<4;i++){
                int new_x=cur_x+dx[i];
                int new_y=cur_y+dy[i];
                if(new_x<0||new_x>=m||new_y<0||new_y>=n) continue;
                if(visited[new_y][new_x]) continue;
                visited[new_y][new_x]=true;
                virus.push({new_x,new_y});
            }    
        }
        int visitcnt=0;
        for(int i=0; i<n; i++) for(int j=0;j<m; j++) if(!visited[i][j])visitcnt++;
        if (visitcnt>ans) ans=visitcnt;

        // if(visitcnt==6){
        //     for(int i=0; i<n; i++){ 
        //     for(int j=0;j<m; j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // }
        // for(int i=0; i<n; i++){ 
        //     for(int j=0;j<m; j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"visitcnt " <<visitcnt<<"\n";
        // int temp;
        // cin>>temp;
    }
    cout<<ans;

    // cout<<wall.size();
    // for(auto& elem:wall)cout<<get<0>(elem)<<","<<get<1>(elem)<<"  "<<get<2>(elem)<<","<<get<3>(elem)<<"  "<<get<4>(elem)<<","<<get<5>(elem)<<"\n";

    // for(int i=0; i<n; i++){elem
    //     for(int j=0;j<m; j++) cout<<map[i][j];
    //     cout<<"\n";
    // }
    return 0;
}