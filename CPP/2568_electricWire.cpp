#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<pair<int,int>> v;
vector<int> lis;
int n;
int scan[100001];

int binarySearch(int key){
    int start =0;
    int end =lis.size()-1;
    int mid;
    while(start<end){
        mid = (start+end)/2;
        if(key>lis[mid]){
            start=mid+1;
        }
        else{
            end=mid;
        }
    }
    return end;
}


int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }

    sort(v.begin(),v.end());
    // for(auto& elem:v) cout<<elem.first<<"  "<<elem.second<<"\n";
    int num_cnt=0;
    for (int i=0; i<n;i++){
        if(lis.empty()||lis.back()<v[i].second){
            scan[i]=num_cnt++;
            lis.push_back(v[i].second);
        }
        else{
            int idx=binarySearch(v[i].second);
            lis[idx]=v[i].second;
            scan[i]=idx;
        }

    }

    // for (int i=0; i<n;i++){
    //     cout<<scan[i]<<" ";
    // }
    // cout<<"\n";

    cout<<n-num_cnt<<"\n";
    int temp=num_cnt-1;
    vector<int> ans;
    for(int i=n-1; i>-1;i--){
        // cout<<"temp "<<temp<<"\n";
        if(temp==scan[i]) temp--;
        else ans.push_back(v[i].first);
    }
    sort(ans.begin(),ans.end());
    for(auto& elem:ans) cout<<elem<<"\n";    

    return 0;
}