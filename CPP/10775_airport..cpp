#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int parent[100001];
int findParent(int x){
    if(parent[x]==x) return x;
    return parent[x]=findParent(parent[x]);
}
void unionParent(int a, int b){
    a=findParent(a);
    b=findParent(b);
    if(a<b) parent[b]=a;
    else parent[a]=b;
}

int main(){
    int Gate, Plane;
    cin>>Gate>>Plane;
    for (int i=0; i<Gate+1; i++){
        parent[i]=i;
    }
    int cnt=0;

    for(int i=1; i<=Plane; i++){
        int x;
        cin>>x;
        int root = findParent(x);
        if(root == 0){
            break;
        }
        else {
            unionParent(root, root-1);
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}