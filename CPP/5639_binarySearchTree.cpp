#include<iostream>
#include<vector>
using namespace std;
vector<int> v;

void postOrder(int start,int end){
    if(start>=end) return;
    
    int root= v[start];
    int vi=start+1;
    while(vi<end){
        if(root<v[vi]) break;
        vi++;
    }
    postOrder(start+1,vi);
    postOrder(vi,end);
    cout<< root<<"\n";
}


int main(){
    int num;
    while (cin>>num) v.push_back(num);

    postOrder(0,v.size());
    // for(auto& elem:v) cout<<elem<<" ";


    return 0;
}