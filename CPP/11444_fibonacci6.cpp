#include<iostream>
#include<unordered_map>

#define mod 1000000007
using namespace std;

unordered_map<long long int,long long int> fibo;

long long int fibonacci(long long int n){
    if(n==0) return fibo[0];
    if(fibo[n])return fibo[n];

    long long int result;
    if(n%2==0) result = ((fibonacci(n / 2) % mod) * ((fibonacci(n / 2 + 1) % mod + fibonacci(n / 2 - 1) % mod) % mod)) % mod;
    else result =((((fibonacci((n + 1) / 2) % mod) * (fibonacci((n + 1) / 2) % mod)) % mod) + (((fibonacci((n - 1) / 2) % mod) * (fibonacci((n - 1) / 2) % mod)) % mod)) % mod;
    fibo[n]=result;
    return result;
}

int main(){
    long long int n;
    cin>>n;
    fibo[0]=0;
    fibo[1]=1;
    fibo[2]=1;
    cout<<fibonacci(n);


    return 0;
}