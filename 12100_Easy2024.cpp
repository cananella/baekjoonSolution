#include<iostream>
#include<deque>
#include<algorithm>

using namespace std;

int n, ans;
int map[20][20];
int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
int tempMap[20][20];

void blockMoveP(bool isAxisX, int copyMap[][20]){
    deque<int> dq[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tempMap[i][j]=0;
            if (copyMap[i][j]==0) continue;
            if (isAxisX) dq[i].push_back(copyMap[i][j]);
            else dq[j].push_back(copyMap[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        int col=n-1;
        while(!dq[i].empty()){
            int num=dq[i].back();
            dq[i].pop_back();
            if(dq[i].empty()) {
                if (isAxisX) tempMap[i][col--]=num;
                else tempMap[col--][i]=num;
                continue;
            }
            if (num==0) continue;
            else if(num==dq[i].back()){
                dq[i].pop_back();
                num*=2;
                if (isAxisX) tempMap[i][col--]=num;
                else tempMap[col--][i]=num;
            }
            else {
                if (isAxisX) tempMap[i][col--]=num;
                else tempMap[col--][i]=num;
            }
        }
    }
    return ;
}

void blockMoveM(bool isAxisX, int copyMap[][20]){
    deque<int> dq[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tempMap[i][j]=0;
            if (copyMap[i][j]==0) continue;
            if (isAxisX) dq[i].push_back(copyMap[i][j]);
            else dq[j].push_back(copyMap[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        int col=0;
        while(!dq[i].empty()){
            int num=dq[i].front();
            dq[i].pop_front();
            if(dq[i].empty()) {
                if (isAxisX) tempMap[i][col++]=num;
                else tempMap[col++][i]=num;
                continue;
            }
            if (num==0) continue;
            else if(num==dq[i].front()){
                dq[i].pop_front();
                num*=2;
                if (isAxisX) tempMap[i][col++]=num;
                else tempMap[col++][i]=num;
            }
            else {
                if (isAxisX) tempMap[i][col++]=num;
                else tempMap[col++][i]=num;
            }
        }
    }
    return;
}

void printMap(int pMap[][20]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< pMap[i][j]<<" ";
        }
        cout<<"\n";
    }
    return;
}

void dfs(int depth , int arr[][20]){
    if(depth ==5){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, tempMap[i][j]);
            }
        }
        return;

    }

    int cparr[20][20];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cparr[i][j] = arr[i][j];
        }
    }

    for (int i = 0; i < 4; i++) {
        switch (i) {
        case 0:
            blockMoveM(true,arr);
            break;
        case 1:
            blockMoveM(false,arr);
            break;
        case 2:
            blockMoveP(true,arr);
            break;
        case 3:
            blockMoveP(false,arr);
            break;
        }

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = tempMap[i][j];
            }
        }
        // cout<<depth<< "  depth \n";
        // printMap(map);
        // int t;
        // cin>>t;

        dfs(depth +1 ,map);

        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = cparr[i][j];
            }
        }
    }
    return;
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    // blockMoveM(true,map);
    // printMap(tempMap);
    dfs(0,map);
    cout<<ans;

    return 0;
}