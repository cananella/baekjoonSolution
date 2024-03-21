#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

deque<int> R(deque<int> list){
    deque<int> temp;
    for (int i=0; i<list.size();i++){
        temp.push_back(list[list.size()-1-i]);
    }
    return temp;
}


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string func, numlist;
        cin>> func;
        int list_size;
        cin >> list_size;
        cin >> numlist;
        deque<int> list;
        int num=0;
        for(int j=0; j<numlist.size();j++){
            if(numlist[j]=='[') continue;
            else if(numlist[j]==']'&&numlist[j-1]=='[') continue;
            else {
                if(numlist[j]==','||numlist[j]==']'){
                    list.push_back(num);
                    num=0;
                }
                else{
                    num=num*10+int(numlist[j])-48;
                }
                
            }
        }
        bool errorflag=0;
        bool reverseflag=0;
        for(int j=0; j<func.size();j++){
            if(func[j]=='R'){
                reverseflag= !reverseflag;
                // list=R(list);  //시간복잡도 문제로 시간초과 오류
                // for (int i=0; i<list.size();i++)cout<<list[i];
                // cout<<endl;
            }
            else if(func[j]=='D'){
                // cout<<"listszie "<< list.size()<<endl;
                if(list.size()>0&&reverseflag==false) list.pop_front();
                else if(list.size()>0&&reverseflag==true) list.pop_back();
                else errorflag=true;    
            }
        }

        // cout<<"listszie "<< list.size()<<endl;

        if(errorflag){
            cout<<"error"<<endl;
        }
        else if(!list.size()) cout<<"[]"<<endl;
        else {

            if(reverseflag){
                cout<<'['<<list[list.size()-1];
                for(int j=1; j<list.size(); j++) cout<<','<<list[list.size()-1-j];
                cout<<']'<<endl;
            }
            else{
                cout<<'['<<list[0];
                for(int j=1; j<list.size(); j++) cout<<','<<list[j];
                cout<<']'<<endl;
            } 
        }
        list.clear();


    }

    return 0;
}