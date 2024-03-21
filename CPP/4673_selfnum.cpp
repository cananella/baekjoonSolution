#include<iostream>

using namespace std;
int main(){
    int numbers[10000];
    for(int i =1;i<10001;i++){
        int temp =i;
        int a=i;
        while(a !=0){
            temp+=a%10;
            a/=10;
        }
        if(temp<=10000){
            numbers[temp-1]=1;
        }

    }

    for(int i=0;i<10000;i++) if(numbers[i]!=1) cout<<i+1<<endl;
    return 0;
}