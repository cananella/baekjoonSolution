#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    char s[m];
    cin>>s;

    // char ans_s[n+2*n];
    // for(int i=0;i<2*n+1;i++) ans_s[i]=(i%2==0)? 'I' : 'O';
    int ans=0;
    for(int i=1;i<m;i++){
        int cnt=0;
        if(s[i-1]=='I'){
            while(s[i]=='O'&&s[i+1]=='I'){
                i+=2;
                cnt++;
                if(cnt==n){
                    cnt--; 
                    ans++;
                }
            }
        }
        
    }
    cout<<ans;


    // for (int i=0;i<(n+2*n);i++){
    //     cout<<ans_s[i]<<" ";
    // }   


    return 0;
}