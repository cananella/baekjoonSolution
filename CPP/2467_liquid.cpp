#include<iostream>
#include<vector>

using namespace std;

int liquid[100000];
int n;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>liquid[i];
    }
    int start=0;
    int end=n-1;
    int min=abs(liquid[start]+liquid[end]);
    int ans[2]={liquid[start],liquid[end]};
    while (start<end){
        int mix=liquid[start]+liquid[end];
        if (min>abs(mix)){
            min=abs(mix);
            ans[0]=liquid[start];
            ans[1]=liquid[end];
        }
        if(mix>0) end--;
        else start++;
    }

    cout<<ans[0]<<" "<<ans[1];
    return 0;
}