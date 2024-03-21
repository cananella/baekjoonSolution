#include<iostream>
#include<algorithm>


using namespace std;


int map[100001][3];
int dpdata[3];
int n;

void dplow(int y){
    int temp[3];
    for(int i=0;i<3;i++){
        int low=dpdata[i]+map[y][i];
        int start,end;
        if     (i==0){start=0;end=2;}
        else if(i==1){start=0;end=3;}
        else if(i==2){start=1;end=3;} 

        for(int j=start;j<end;j++){
            if(low > dpdata[j]+map[y][i]) low=dpdata[j]+map[y][i];
        }
        temp[i]=low;
    }
    for(int i=0;i<3;i++)dpdata[i]=temp[i];
    if(y!=n){
        dplow(y+1);
    }
}
void dphigh(int y){
    int temp[3];
    for(int i=0;i<3;i++){
        int high=dpdata[i]+map[y][i];
        int start,end;
        if     (i==0){start=0;end=2;}
        else if(i==1){start=0;end=3;}
        else if(i==2){start=1;end=3;} 

        for(int j=start;j<end;j++){
            if(high < dpdata[j]+map[y][i]) high=dpdata[j]+map[y][i];
        }
        temp[i]=high;   
    }
    for(int i=0;i<3;i++) dpdata[i]=temp[i];

    if(y!=n){
        dphigh(y+1);
    }
}


int main(){
    cin>>n;
    for(int i=0;i<3;i++) {
        map[0][i]=0;
        dpdata[i]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>map[i][0]>>map[i][1]>>map[i][2];
    }

    
    dplow(1);
    int l=dpdata[0];
    for(int i=1;i<3;i++){
        if(l>dpdata[i]) l=dpdata[i];
    }

    for(int i=0;i<3;i++) {
        dpdata[i]=0;
    }
    
    dphigh(1);
    int h=dpdata[0];   
    for(int i=1;i<3;i++){
        if(h<dpdata[i]) h=dpdata[i];
    }
    cout<<h<<" "<<l;

    return 0;
}