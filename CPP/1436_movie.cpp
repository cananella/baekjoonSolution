#include<iostream>


using namespace std;

bool chack_num(string a){
    int size=a.size();
    int count=0;
    int max_cnt=0;
    for (int i=0;i<size;i++){
        if(a[size-i-1]=='6') {
            count++;
            if (count>max_cnt) max_cnt=count;
        }
        else count=0;
        
    }
    if (max_cnt>=3) return true;
    else return false;
}


int main(){
    int cnt,n;
    cin>>n;
    int num=666;
    cnt=0;
    int temp;
    while(n!=cnt){
        string data=to_string(num);
        if (chack_num(data)){
            cnt++;
            if(n==cnt) continue;
            num++;
        }else{
            num++;
        }
    }

    cout<<num;

    return 0;
}