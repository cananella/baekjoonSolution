#include<iostream>
#include<stack>
#include<string>


using namespace std;


int main(){

    string str;
    cin>>str;

    stack<char> op;
    for(int i=0;i<str.size();i++){
        if(str[i]>='A'&&str[i]<='Z') cout<<str[i];
        if(str[i]=='*'||str[i]=='/'){
            if(op.empty())op.push(str[i]);
            else {
                while(!op.empty()&&(op.top()=='*'||op.top()=='/')){
                    cout<<op.top();
                    op.pop();
                }
                op.push(str[i]);
            } 
        }
        if(str[i]=='+'||str[i]=='-'){
            if(op.empty())op.push(str[i]);
            else {
                while(!op.empty()&&(op.top()=='*'||op.top()=='/'||op.top()=='+'||op.top()=='-')){
                    cout<<op.top();
                    op.pop();
                }
                op.push(str[i]);
            }
        }
        if(str[i]=='(')op.push(str[i]);
        if(str[i]==')'){
            while(op.top()!='('){
                cout<<op.top();
                op.pop();
            }
            op.pop();
        }
    }
    while(!op.empty()){
        cout<<op.top();
        op.pop();
    }



    return 0;
}