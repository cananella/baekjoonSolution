#include<iostream>
#include<algorithm>

using namespace std;


int main(){

    int n,m;

    cin>>n>>m;
    int trees[n];
    for (int i=0;i<n;i++){
        cin>>trees[i];
    }
    sort(trees,trees+n);
    int start=0;
    int end=trees[n-1];
    long long int ans=0;
    int cutpoint;
    int result;
    while(start<=end){
        cutpoint=(start+end)/2;
        // cout<<"start end cutp "<<start<<" "<<end<<" "<<cutpoint<<endl;
        ans=0;
        for (int i=0;i<n;i++){
            if(trees[i]>cutpoint) ans+=trees[i]-cutpoint;
        }
        if (ans<m) end=cutpoint-1;
        else {
            result =cutpoint;
            start = cutpoint+1;
        }
        // cout<<"changed start end "<<start<<" "<<end<<endl;
    }

    cout<<result;
    // for(int i=0;i<n;i++) cout<<trees[i];


    return 0;
}