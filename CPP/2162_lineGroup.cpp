#include<iostream>
#include<vector>
#include<tuple>

using namespace std;

vector <tuple<int,int,int,int>> points;
int n;
int parent[3000];

int ccw(pair<int,int> p1, pair<int,int> p2, pair<int,int> p3){
    int op = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    op -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);
    if (op>0) return 1;
    else if(op==0) return 0;
    else return -1;
}

int isCrossed( tuple<int,int,int,int> p1, tuple<int,int,int,int> p2){
    pair<int,int> a = {get<0>(p1),get<1>(p1)};
    pair<int,int> b = {get<2>(p1),get<3>(p1)};
    pair<int,int> c = {get<0>(p2),get<1>(p2)};
    pair<int,int> d = {get<2>(p2),get<3>(p2)};
    int ab = ccw(a,b,c)*ccw(a,b,d);
    int cd = ccw(c,d,a)*ccw(c,d,b);
    if(ab==0&&cd==0){
        if(a>b)swap(a,b);
        if(c>d)swap(c,d);
        return c<=b && a<=d;
    }
    return ab<=0 && cd<=0;
}
int find(int a){
    if(parent[a]==a) return a;
    return find(parent[a]);
}

void unionP(int a, int b){
    a= find(a);
    b= find(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
    return;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        points.push_back({a,b,c,d});
        parent[i]=i;
    }
    // cout<< isCrossed(points[0],points[1]);

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<=n-1;j++){
            if(isCrossed(points[i],points[j])){
                cout<<i<<" , "<<j<<" is Crossed\n";
                unionP(i,j);
            }
        }
    }

    cout<<"\n";
    for(int i=0;i<n;i++) cout<<parent[i]<<" ";
    cout<<"\n";

    vector<int> v[3000];
    int gCnt=0;
    int maxSize=0;
    for(int i=0;i<n;i++) v[find(i)].push_back(i);
    
    for(auto elem:v){
        if(elem.empty())continue;
        gCnt++;
        // cout<<gCnt-1<<" is root\n";
        if(maxSize<elem.size()) maxSize=elem.size();
    }
    
    
    cout<<gCnt<<"\n"<<maxSize;

    return 0;
}