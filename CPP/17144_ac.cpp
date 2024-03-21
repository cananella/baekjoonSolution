#include<iostream>

using namespace std;
int map[50][50]={0,};
int r,c,t;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void defuse(){
    int batch[r][c];
    for(int i=0;i<r;i++)for(int j=0;j<c;j++) batch[i][j]=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j]>0){
                int defuse_num=0;
                for(int loop=0;loop<4;loop++){
                    int new_x=j+dx[loop];
                    int new_y=i+dy[loop];
                    if(new_x<0||new_y<0||new_x>=c||new_y>=r) continue;
                    if(map[new_y][new_x]==-1)continue;
                    batch[new_y][new_x] +=map[i][j]/5;
                    defuse_num++;
                }
                batch[i][j]+=map[i][j]-map[i][j]/5*defuse_num;
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j]>=0)map[i][j]=batch[i][j];
        }
    }
}
void rotate(int u_x,int u_y,int d_x,int d_y){
    int temp1=0;
    int temp2;
    //upside
    for(int i=1;i<c;i++){
        temp2=map[u_y][i];
        map[u_y][i]=temp1;
        temp1=temp2;
    }
    for(int i=u_y-1;i>=0;i--){
        temp2=map[i][c-1];
        map[i][c-1]=temp1;
        temp1=temp2;
    }
    for(int i=c-2;i>=0;i--){
        temp2=map[0][i];
        map[0][i]=temp1;
        temp1=temp2;
    }
    for(int i=1;i<u_y;i++){
        temp2=map[i][0];
        map[i][0]=temp1;
        temp1=temp2;
    }
    //down side
    temp1=0;
    temp2=0;
    for(int i=1;i<c;i++){
        temp2=map[d_y][i];
        map[d_y][i]=temp1;
        temp1=temp2;
    }
    for(int i=d_y+1;i<r;i++){
        temp2=map[i][c-1];
        map[i][c-1]=temp1;
        temp1=temp2;
    }
    for(int i=c-2;i>=0;i--){
        temp2=map[r-1][i];
        map[r-1][i]=temp1;
        temp1=temp2;
    }
    for(int i=r-2;i>d_y;i--){
        temp2=map[i][0];
        map[i][0]=temp1;
        temp1=temp2;
    }
}

void printmap(){
    cout<<"\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
}


int main(){
    
    cin>>r>>c>>t;
    int up_ac_x,up_ac_y,down_ac_x,down_ac_y;
    int ac_flag=true;
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>map[i][j];
            if(ac_flag&&map[i][j]==-1){
                up_ac_x=j; up_ac_y=i;down_ac_x=j;down_ac_y=i+1;
                ac_flag=false;
            }
        }
    }
    // defuse();
    // rotate(up_ac_x,up_ac_y,down_ac_x,down_ac_y);
    // printmap();

    while(t--){
        defuse();
        rotate(up_ac_x,up_ac_y,down_ac_x,down_ac_y);
    }
    int ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(map[i][j]>0) ans+=map[i][j];
        }
    }

    cout<<ans;



    return 0;
}