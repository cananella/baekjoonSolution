#include<iostream>
#include<queue>
#include<vector>
#include<tuple>
using namespace std;

int n,m;
int tempMap[50][50];
vector<pair<int,int>> chickPoint;
vector<pair<int,int>> housePoint;
vector<int> pointPicked;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

int solve(vector<pair<int,int>>& chick){
    int cost=0;
    for(auto& house:housePoint){
        int dist=1e9;
        int houseX=house.first;
        int houseY=house.second;
        for(auto& chicken:chick){
            int chickX=chicken.first;
            int chickY=chicken.second;
            dist=min(dist,abs(houseX-chickX)+abs(houseY-chickY));
        }
        cost+=dist;
    }
    return cost;
}

void pick(int num, vector<int>& picked, int toPick){
    if(toPick==0){
        for(auto& elem:picked){
            pointPicked.push_back(elem);
        }
        return;
    }
    int smallest = picked.empty()? 0 : picked.back()+1;
    for(int i=smallest; i<num;i++){
        picked.push_back(i);
        pick(num,picked,toPick-1);
        picked.pop_back();
    }
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p;
            cin>>p;
            if(p==1) housePoint.push_back({j,i});
            else if(p==2) chickPoint.push_back({j,i});
        }
    }
    vector<int> v;
    pick(chickPoint.size(),v,m);

    int mincost=1e9;
    while(!pointPicked.empty()){
        vector<pair<int,int>> tempChick;
        for(int i=0;i<m;i++){
            pair<int,int> p =chickPoint[pointPicked.back()];
            tempChick.push_back(p);
            pointPicked.pop_back();
        }

        mincost=min(mincost,solve(tempChick));
        // cout<<"\n";
        // cout<<"cost is "<<bfs() <<"\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<tempMap[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
    }
    cout<<mincost;

    return 0;
}