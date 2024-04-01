#include<iostream>
#include<string>
#include<vector>

using namespace std;

int map[9][9];
int tempmap[9][9];
vector<pair<int,int>> v;

void printMap(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
}

void chackMap(int n){
    if(n==v.size()) {
        printMap();
        exit(0);
    }
    int x=v[n].first;
    int y=v[n].second;
    for(int num=1;num<=9;num++){
        bool flag=true;
        for(int i=0;i<9;i++){
            if(map[y][i]==num) flag=false;
            if(map[i][x]==num) flag=false;
        }
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(map[int(y/3)*3+i][int(x/3)*3+j]==num) flag=false;
            }
        }
        if(flag) {
            map[y][x]=num;
            chackMap(n+1);
            map[y][x]=0;
        }
    }
    return;
}

int main(){
    for(int i=0;i<9;i++){
        string str;
        cin>>str;
        for(int j=0;j<9;j++){
            map[i][j]=int(str[j])-'0';
            if(map[i][j]==0) v.push_back({j,i});
        }
    }

    chackMap(0);

    return 0;
}