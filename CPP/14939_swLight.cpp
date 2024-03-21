#include<iostream>


using namespace std;
bool map[10][10],temp[10][10];

int dx[5]={0,0,0,1,-1};
int dy[5]={0,1,-1,0,0};
void SW(int y,int x){
    for(int i=0;i<5;i++){
        int newy=y+dy[i];
        int newx=x+dx[i];
        if(newy<0||newx<0||newy>=10||newx>=10) continue;
        temp[newy][newx]=(temp[newy][newx])? false:true;
    }
    return;
}
void initTEMP(){
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) temp[i][j]=map[i][j];
}

bool isOn(){
    for(int i=0; i<10; i++) for(int j=0; j<10; j++) if(temp[i][j]) return true;
    return false;
}



int main(){
    string line;
    for(int i=0; i<10; i++){
        cin>>line;
        for(int j=0; j<10; j++) map[i][j]=(line[j]=='#')?false:true;
    }

    int ans=1025;
    for(int i=0; i< 1<<10;i++){
        int cnt=0;
        initTEMP();

        

        for(int bit=0;bit<10;bit++){
            if(i & (1<<bit)){
                SW(0,bit);
                cnt++;
            }
        }

        // for(int i=0; i<10; i++){
        //     for(int j=0; j<10; j++) cout<<temp[i][j]<<" ";
        //     cout<<"\n";
        // }
        // cout<<"\n";
        // int asdf;
        // cin>>asdf;

        for(int row=1;row<10;row++){
            for(int col=0;col<10;col++){
                if(! temp[row-1][col])continue;
                SW(row,col);
                cnt++;
            }
        }


        // for(int i=0; i<10; i++){
        //     for(int j=0; j<10; j++) cout<<temp[i][j]<<" ";
        //     cout<<"\n";
        // }
        // cout<<"\n";
        // int qwer;
        // cin>>qwer;

        if(!isOn()) ans=min(ans,cnt);

    }
    if(ans==1025) cout<<-1;
    else cout<<ans;




    // SW(map,1,1);

    // for(int i=0; i<10; i++){
    //     for(int j=0; j<10; j++) cout<<map[i][j]<<" ";
    //     cout<<"\n";
    // }
    

    return 0;
}
