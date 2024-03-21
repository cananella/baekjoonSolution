#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct word{
    string data;
    int data_size;
};

bool comp(const word& a, const word& b){
    if(a.data_size==b.data_size) return a.data<b.data;
    else return a.data_size<b.data_size;

}


int main(){
    int n;
    cin>>n;
    vector <word> v;
    for (int i=0; i<n;i++){
        string w;
        int s;
        cin>>w;
        s=w.size();
        v.push_back({w,s});
    }
    sort(v.begin(),v.end(),comp);

    cout<<v[0].data<<endl;
    for(int i=1;i<n;i++) if(v[i].data!=v[i-1].data) cout<<v[i].data<<endl;
 

    return 0;
}

