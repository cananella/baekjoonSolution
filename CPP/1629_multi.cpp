#include<iostream>

using namespace std;

long long a,b,c;

long long Pow(long long a,long long b,long long c){
    if(b==0) return 1;
    if(b==1) return a%c;
    long long temp = Pow(a,b/2,c)%c;
    temp =temp*temp%c;
    if(b%2==0) return temp;
    else return temp*(a%c);
}

int main (){

    cin>>a>>b>>c;
    long long ans=Pow(a,b,c)%c;
    cout<<ans;

    return 0;
}