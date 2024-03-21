#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int n,m,k;
int parents[4000001];

int find(int num){
    if(parents[num]==num) return parents[num];
    else return find(parents[num]);
}

void unionParent(int a,int b){
    a=find(a);
    b=find(b);
    if(a>b) parents[b]=a;
    else parents[a]=b;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>m>>k;

    vector<int> num;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        num.push_back(temp);
    }
    sort(num.begin(),num.end());
    for(int i=0;i<m;i++) parents[i]=i;

    for(int i=0;i<k;i++){
        
        int temp;
        cin>>temp;

        int idx = lower_bound(num.begin(),num.end(),temp+1)-num.begin();
        cout<<num[find(idx)]<<"\n";
        
        // cout<<"idx= "<<idx<<"\n";
        // cout<<"union : "<<num[find(idx)]<<", "<<num[find(idx)+1]<<"\n";
        if(idx<m-1) unionParent(find(idx),find(idx)+1);
        
        // cout<<"num list: ";
        // for(auto& elem:num) cout<<elem<<" ";
        // cout<<"\n";
        // cout<<"parents:  ";
        // for(int i=0;i<m;i++) cout<<parents[i]<<" ";
        // cout<<"\n\n";
    }

    return 0;
}