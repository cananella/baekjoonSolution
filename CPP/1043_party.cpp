#include<iostream>
#include<vector>
using namespace std;

int n,m,k;
int parents[51];
vector <int> know;
vector <vector<int>> v(50);

int Find(int x){
    if(parents[x]==x)return x;
    return x=Find(parents[x]);
}

void Union(int prev,int num){
    prev=Find(prev);
    num =Find(num);
    parents[prev]=Find(parents[num]);
}

int main(){
    cin>>n>>m;

    int p;
    cin>>p;
    for (int i=0;i<p;i++){
        int num;
        cin>>num;
        know.push_back(num);
    }
    for(int i=1;i<=n;i++) parents[i]=i;
    
    for(int i=0;i<m;i++){
        int p;
        cin>>p;
        int num,prev;
        for(int j=0;j<p;j++){
            if(j>=1){
                prev=num;
                cin>>num;
                Union(prev,num);
            }else{
                cin>>num;
            }
            v[i].push_back(num);
        }
    }
    for(auto list :v){
        bool flag =false;
        for(auto& person:list){
            if(flag) break;
            for(auto& t:know){
                if(Find(person)==Find(t)){
                    flag=true;
                    break;
                }
            }
        }
        if(flag)m--;
    }
    cout<<m;
    return 0;
}