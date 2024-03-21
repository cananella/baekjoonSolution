#include<iostream>
#include<queue>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(){
    int n; 
    scanf("%d",&n);

    int map[n][n];
    for (int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&map[i][j]);
            }
    }
    int num_of_vil=0;
    queue <pair<int,int>> q;
    queue <int> list;
    for (int i =0;i<n;i++){
        for(int j=0;j<n;j++){

            if(map[i][j]==1){
                q.push(make_pair(i,j));
                map[i][j]=0;
                int cnt=1;
                while(!q.empty()){

                    pair<int,int> cur = q.front();
                    q.pop();

                    for (int k=0;k<4;k++){
                        int newx=cur.first+dx[k];
                        int newy=cur.second+dy[k];
                        if(newx<0||newx>=n||newy<0||newy>=n)continue;
                        if(map[newx][newy]==0)continue;
                        map[newx][newy]=0;
                        cnt++;
                        q.push(make_pair(newx,newy));

                        // char temp;
                        // cin>>temp;
                        // cout<<newx<<" "<<newy <<","<<cnt<<endl;
                        // for (int i =0;i<n;i++){
                        //     for(int j=0;j<n;j++){
                        //         cout<<map[i][j];
                        //     }
                        //     cout<<endl;
                        // }
                    }
                }
                if (cnt!=0) list.push(cnt);
            }
        }
    }
    num_of_vil=list.size();
    cout<<num_of_vil<<endl;
    int vil[num_of_vil];
    for (int i=0; i<num_of_vil; i++){
        vil[i]=list.front();
        list.pop();
    }

    qsort(vil,num_of_vil,sizeof(int),compare);
    for (int i=0; i<num_of_vil; i++) cout<<vil[i]<<endl;
   


    // for (int i =0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<map[i][j];
    //     }
    //     cout<<endl;
    // }
    

    return 0;
}