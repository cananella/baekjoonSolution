#include<iostream>
#include<string>

using namespace std;
int lcs[1001][1001];

int main(){

    string a,b;
    cin>>a>>b;
    for(int i=0;i<=b.size();i++) for(int j=0;j<=a.size();j++) lcs[i][j]=0;
    // cout<<a[0]<<b[0]<<a[a.size()-1]<<b[b.size()-1]<<"\n";
    for(int i=0;i<b.size();i++){
        for(int j=0;j<a.size();j++){
            if(a[j]==b[i]) lcs[i+1][j+1]=lcs[i][j]+1;
            else lcs[i+1][j+1]=max(lcs[i][j+1],lcs[i+1][j]);
        }
    }
    // for(int i=0;i<=b.size();i++){
    //     for(int j=0;j<=a.size();j++){
    //         cout<<lcs[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // } 
    cout<<lcs[b.size()][a.size()];

    return 0;
}
