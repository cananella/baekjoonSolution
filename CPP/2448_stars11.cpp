#include<iostream>

using namespace std;
char map[3073][6145];

void maketree(int n,int x,int y){
    if(n==3){
        map[y][x]='*';
        map[y+1][x-1]='*';
        map[y+1][x+1]='*';
        for(int i=0;i<5;i++) map[y+2][x-2+i]='*';
    }
    else{
        maketree(n/2,x,y);
        maketree(n/2,x-n/2,y+n/2);
        maketree(n/2,x+n/2,y+n/2);
    }
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)for(int j=1;j<=2*n;j++) map[i][j]=' ';
    maketree(n,n,1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=2*n;j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }

}