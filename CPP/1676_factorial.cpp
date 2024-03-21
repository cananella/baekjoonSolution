#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int two_cnt,five_cnt;
    two_cnt=0;
    five_cnt=0;
    for(int i=1;i<=n;i++){
        int num=i;
        while(num!=0){
            if(!(num%2)) {
                two_cnt++;
                num /=2;
            }else break;
        }
        num=i;
        while(num!=0){
            if(!(num%5)) {
                five_cnt++;
                num /=5;
            } else break;
        }
    }

    int ans=(two_cnt>=five_cnt)?five_cnt:two_cnt;

    cout<<ans;



    return 0;
}