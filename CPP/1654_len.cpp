#include<iostream>

using namespace std;

int main(){
    int k, n;
    cin>>k>>n;
    int lines[n];
    long long min_length=1;
    long long max_length=0;
    for (int i=0;i<k;i++) {
        cin>>lines[i];
        if(lines[i]>max_length) max_length=lines[i];
    }
    
    long long cnt=0;
    long long length=0;
    long long ans;

    while(min_length<=max_length){
        cnt=0;
        length=(min_length+max_length)/2;


        for (int i=0;i<k;i++){
            cnt+=lines[i]/length;
        }

        if(n<=cnt) {
            min_length=length+1;
            ans=length;
        }
        else max_length=length-1;


    }
    cout<<ans; 

    return 0;
}