#include<iostream>
#include<vector>


using namespace std;
int backpack[101][100001];
int W[101]={0,};
int V[101]={0,};
int n,k;

void dp(){
    for(int limit=1;limit<=k;limit++){
        for(int row=1;row<=n;row++){
            if(W[row]>limit) backpack[row][limit]=backpack[row-1][limit];
            else backpack[row][limit]=max(backpack[row-1][limit], backpack[row-1][limit-W[row]]+V[row]);
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>W[i]>>V[i];
    }
    for(int i=0; i<=n; i++) backpack[i][0]=0;
    for(int i=0; i<=k; i++) backpack[0][i]=0;

    dp();

    cout<<backpack[n][k];


    return 0;
}