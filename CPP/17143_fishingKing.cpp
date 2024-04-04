#include<iostream>
#include<queue>
#include<tuple>

using namespace std;
int R,C,M;
int remain_sharks_number=0;
priority_queue<tuple<int,int,int>> sharks[101][101];
int captured_size=0;

int dx[5]={0,0,0,1,-1};
int dy[5]={0,-1,1,0,0};

void catching(int manpoint){
    for(int i=1;i<=R;i++){
        if(sharks[i][manpoint].empty()) continue;
        captured_size += get<0>(sharks[i][manpoint].top());
        // cout<<"x  y "<< manpoint<<" "<<i<<" shark captured\n";
        // cout<<"size of shark is "<<get<0>(sharks[i][manpoint].top())<<"  sum size is "<< captured_size<<"\n";
        sharks[i][manpoint].pop();
        break;
    }
    return;
}

void sharkMove(){
    queue<tuple<int,int,int,int,int>> q;
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(sharks[i][j].empty()) continue;
            int size = get<0>(sharks[i][j].top());
            int speed = get<1>(sharks[i][j].top());
            int direction = get<2>(sharks[i][j].top());
            sharks[i][j].pop();
            q.push({i,j,size,speed,direction});
        }
    }
    while(!q.empty()){
        int curr_y    = get<0>(q.front());
        int curr_x    = get<1>(q.front());
        int size      = get<2>(q.front());
        int speed     = get<3>(q.front());
        int direction = get<4>(q.front());
        q.pop();
        for(int i=0; i<speed; i++){
            if      (direction==3 && curr_x==C) direction=4;
            else if (direction==4 && curr_x==1) direction=3;
            else if (direction==1 && curr_y==1) direction=2;
            else if (direction==2 && curr_y==R) direction=1;
            curr_x=curr_x+dx[direction];
            curr_y=curr_y+dy[direction];
        }
        sharks[curr_y][curr_x].push({size,speed,direction});
    }

    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(sharks[i][j].size()<2) continue;
            int size = get<0>(sharks[i][j].top());
            int speed = get<1>(sharks[i][j].top());
            int direction = get<2>(sharks[i][j].top());
            while(!sharks[i][j].empty()){ 
                sharks[i][j].pop();
                remain_sharks_number--;
            }
            sharks[i][j].push({size,speed,direction});
        }
    }
    return;
}
void printRemainShark(){
    cout<<"\n";
    for(int i=1; i<=R; i++){
        for(int j=1; j<=C; j++){
            if(sharks[i][j].empty())continue;
            cout<<"remain shark x  y "<<j<<" "<<i<<"  size "<<get<0>(sharks[i][j].top())<<"\n";
        }
    }
    cout<<"\n";
    cout<<"\n";
    return;
}

int main(){
    cin>>R>>C>>M;
    for(int i=0; i<M; i++){
        int y,x,speed,direction,size;
        cin>> y>> x>> speed>> direction>> size;
        if (direction<=2) speed %=(R-1)*2;
        else speed %=(C-1)*2;
        sharks[y][x].push({size,speed,direction});
        remain_sharks_number++;
    }

    for(int i=1;i<=C;i++){
        catching(i);
        sharkMove();
        // printRemainShark();
    }
    cout<<captured_size;

    return 0;
}