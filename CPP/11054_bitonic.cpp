#include<iostream>

using namespace std;
int list[1000];
int dpright[1000],dpleft[1000];

int main(){

    int num;
    cin>>num;

    for(int i=0;i<num;i++){
        cin>>list[i];
    }

    for(int i=0;i<num;i++){
        dpright[i]=1;
        dpleft[i]=1;
    }
    
    for(int i=0;i<num;i++){
        for(int j=0; j<i;j++){
            if(list[i]<=list[j])continue;
            if(dpright[i]>=dpright[j]+1) continue;
            dpright[i]++;
        }
    }
    for(int i=0;i<num;i++){
        for(int j=0; j<i;j++){
            if(list[num-1-i]<=list[num-1-j])continue;
            if(dpleft[num-1-i]>=dpleft[num-1-j]+1) continue;
            dpleft[num-1-i]++;
        }
    }

    int ans=0;
    for(int i=0;i<num;i++){
        int bitonic= dpleft[i]+dpright[i]-1;
        ans = bitonic>ans? bitonic:ans;
    }

    cout<<ans;


    return 0;
}