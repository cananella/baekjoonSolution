#include<iostream>

using namespace std;

bool chack_num(string a){
    int str_size=a.size();
    for(int i=0;i<str_size/2;i++){
        if(a[i]!=a[str_size-i-1]) return false;
    }
    return true;
}


int main(){

    int num=1;
    while(num){
        cin>>num;
        string data= to_string(num);
        if(chack_num(data)&&num!=0){
            cout<<"yes"<<endl;
            continue;
        }
        else if(num!=0) cout<<"no"<<endl;
    }
}