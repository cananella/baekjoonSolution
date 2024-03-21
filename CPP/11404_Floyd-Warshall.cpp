#include<iostream>
#define INF 200000000
using namespace std;

int table[101][101];
int n,m;

void printT(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(table[i][j]==INF)cout<<0<<" ";
            else cout<<table[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if (i==j) table[i][j]=0;
            else table[i][j]=INF;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        table[a][b]=min(table[a][b],c);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                table[j][k]=min(table[j][k],table[j][i]+table[i][k]);
            }
        }
    }

    printT();

    
    return 0;
}