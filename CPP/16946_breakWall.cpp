#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<set>

using namespace std;

int n,m;
int map[1000][1000];
int groupNum[1000][1000];
bool visitied[1000][1000];
int zeroAreaNum=0;
int ansMap[1000][1000];
vector<int> zeroAreaSize;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void bfs(int startX, int startY){
    queue<pair<int,int>> q;
    q.push({startX,startY});
    visitied[startY][startX]=true;
    groupNum[startY][startX]=zeroAreaNum;
    int cnt=1;
    while(!q.empty()){
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int newx=curx+dx[i];
            int newy=cury+dy[i];
            if(newx<0||newy<0||newx>=m||newy>=n) continue;
            if(visitied[newy][newx]||map[newy][newx]) continue;
            visitied[newy][newx]=true;
            groupNum[newy][newx]=zeroAreaNum;
            q.push({newx,newy});
            cnt++;
        }
    }
    zeroAreaSize.push_back(cnt);
}


int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        for(int j=0;j<m;j++){
            map[i][j]=int(str[j])-'0';
            groupNum[i][j]=-1;
            visitied[i][j]=false;
            ansMap[i][j]=0;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0&&visitied[i][j]==false) {
                bfs(j,i);
                zeroAreaNum++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if (map[i][j]==1) {
                set<int> search;
                for(int k=0;k<4;k++){
                    int x= j +dx[k];
                    int y= i +dy[k];
                    if(x<0||y<0||x>=m||y>=n) continue;
                    if(map[y][x]) continue;
                    if(search.find(groupNum[y][x])==search.end()){
                        search.insert(groupNum[y][x]);
                        ansMap[i][j]+=zeroAreaSize[groupNum[y][x]];
                    }
                }
                ansMap[i][j] ++;
                ansMap[i][j] %=10;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ansMap[i][j];
        }
        cout<<"\n";
    }


    return 0;
}