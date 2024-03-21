#include<iostream>
#include<cstring>

using namespace std;

int main(){
    int n;
    string str[50];
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        cin>>str[i];
    }

    for (int i=0; i<str[0].length(); i++){
        for (int j=0; j<n; j++){
            if(str[0][i]!=str[j][i]) {
                str[0][i] = '?';
                break;
            }
        }
    }
    cout<<str[0];
    return 0;
}
