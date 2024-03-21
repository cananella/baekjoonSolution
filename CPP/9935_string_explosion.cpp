#include <iostream>
#include <string>
#include<algorithm>
#include <stack>

using namespace std;
stack<char> st;
string str;
string trigger;

int main(){
    cin>>str>>trigger;

    for(int i=0;i<str.length();i++){
        st.push(str[i]);

        if(str[i]==trigger[trigger.length()-1]&&st.size()>=trigger.length()){
            string temp;
            for(int j=0;j<trigger.length();j++){
                temp.push_back(st.top());
                st.pop();
            }
            reverse(temp.begin(),temp.end());
            if(temp.compare(trigger)!=0){
                for(int j=0;j<temp.length();j++)st.push(temp[j]);
            }
        }
    }
    
    stack<char> ans;
    if(st.empty()) cout<<"FRULA";
    else{
        int stsize=st.size();
        for (int i = 0;i<stsize;i++){
            ans.push(st.top());
            st.pop();
        }
        for (int i = 0;i<stsize;i++){
            cout<<ans.top();
            ans.pop();
        }
    }
    

    return 0;
}