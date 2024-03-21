#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>

using namespace std;


int dx[4]={0,-1,1,0};
int dy[4]={-1,0,0,1};

bool compare(tuple<int,int,int,int>a,tuple<int,int,int,int>b){
    if(get<0>(a)==get<0>(b)){
        if(get<2>(a)==get<2>(b)) return get<1>(a) < get<1>(b);
        else return get<2>(a) < get<2>(b);
    }else return get<0>(a) < get<0>(b);
}

bool chackFoodIsLeft(vector<pair<int,int>>* food_V,int shark_size){
    bool flag=false;
    for (int i=1;i<shark_size;i++){
        if(food_V[i].size()>0) {
            flag=true;
            return flag;
            }
    }
    return flag;
}


int main(){

    int n;
    cin>>n;
    int map[n][n];
    int shark_x,shark_y,shark_size=2;
    int num_of_food=0;
    bool visited[n][n]={false,};
    int food_x,food_y,food_size;
    vector<pair<int,int>> food_v[8];
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int num;
            cin>> num;
            map[i][j]=num;
            if(num==9){
                shark_x=j;
                shark_y=i;
                visited[i][j]=true;
            }
            else if(num!=0&&num!=9) {
                num_of_food++;
                food_v[num].push_back(make_pair(j,i));
            }
        }
    }
    queue<tuple<int,int,int>> q;
    

    int time_cnt=0;
    int num_of_ate=0;
    bool flag=true;
    while(flag){                                 //상어 가 먹을수 있는 먹이가 남아있을경우
        vector<tuple<int,int,int,int>> eatabel_fish;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++) visited[i][j]=false; 
        q.push(make_tuple(shark_x,shark_y,0));
        
        while(!q.empty()){                                              //BFS로 최단경로 찾기

            int current_shark_x=get<0>(q.front());
            int current_shark_y=get<1>(q.front());
            int current_shark_cnt=get<2>(q.front());
            q.pop();
            // cout<<"cur_XY CNT "<< current_shark_x<<" "<<current_shark_y<<" "<<current_shark_cnt<<endl;
            for(int i=0;i<4;i++){
                int new_x=current_shark_x+dx[i];
                int new_y=current_shark_y+dy[i];
                int new_cnt=current_shark_cnt+1;

                if(new_x<0||new_y<0||new_x>=n||new_y>=n)continue;                   // 보드를 벗어날경우 건너뛰기
                if(visited[new_y][new_x])continue;                                  // 이미 방문한 노드 건너뛰기
                if(map[new_y][new_x]>shark_size&&map[new_y][new_x]!=9)continue;     // 자기보다 큰 물고기가 있는경우 건너뛰기
                // cout<<"new_XY CNT "<< new_x<<" "<<new_y<<" "<<new_cnt<<endl;
                visited[new_y][new_x]=true;
                q.push(make_tuple(new_x,new_y,new_cnt));    ///////////////////////////////////
                int size=(shark_size>6)? 7:shark_size;
                for(int j=1;j<size;j++){                                            
                    for(auto& elem:food_v[j]){                         
                        if(elem.first==new_x&&elem.second==new_y) eatabel_fish.push_back(make_tuple(new_cnt,new_x,new_y,j));  //이동한곳에 물고기가있고 먹을수있을때
                    }
                }
            }
        }
        if(eatabel_fish.empty()) flag=false;
        else{
            sort(eatabel_fish.begin(),eatabel_fish.end(),compare);
            int fish_cnt=get<0>(eatabel_fish[0]);
            int fish_x =get<1>(eatabel_fish[0]);
            int fish_y =get<2>(eatabel_fish[0]);
            int fish_size =get<3>(eatabel_fish[0]);
            eatabel_fish.clear();
            for(int i=0;i<food_v[fish_size].size();i++){
                if(food_v[fish_size][i].first==fish_x&&food_v[fish_size][i].second==fish_y) 
                    food_v[fish_size].erase(food_v[fish_size].begin()+i);
            }
            shark_x=fish_x;                                           // 상어의 위치 갱신
            shark_y=fish_y;
            num_of_ate++;                                            // 먹이 먹은 갯수 +1
            time_cnt+=fish_cnt;                                      // 총이동횟수에 BFS 최단경로 +
            num_of_food--; 
        }
        if(shark_size==num_of_ate){                                   // 상어 크기만큼 먹이를 먹었을경우
            shark_size++;                                             // 상어 크기 +1 먹은 먹이수 초기화
            num_of_ate=0;
        }
    }

    cout<<time_cnt;

    return 0;
}