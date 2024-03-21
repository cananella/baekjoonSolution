#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

int D(int num){
    int ans= num*2 % 10000;
    return ans;
}

int S(int num){
    int ans= num-1;
    return ans;
}
int L(int num){
    int ans;
    if(!num) ans=9999;
    else ans=(num*10)%10000+num/1000;
    return ans;
}

int R(int num){
    int ans;
    ans=num/10+(num%10)*1000;
    return ans;
}

bool visited[10001];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int num, dest;
        cin>>num>>dest;
        queue<pair<int,string>> q;
        q.push(make_pair(num,""));
        memset(visited,false,sizeof(visited));
        visited[num]=true;
        // cout <<"D:"<<D(num) <<"  S:"<<S(num) <<"  L:"<<L(num) <<"  R:"<<R(num) <<endl;
        bool flag=1;
        int currnt_num, new_num;
        string current_op, new_op;
        while(!q.empty()&&flag){
            currnt_num= q.front().first;
            current_op=q.front().second;
            q.pop();
            // cout<<current_op<<current_op<<endl;
            for(int i=0;i<4;i++){
                switch(i){
                    case 0:
                        new_num=D(currnt_num);
                        new_op=current_op+"D";
                        break;
                    case 1:
                        new_num=S(currnt_num);
                        new_op=current_op+"S";
                        break;
                    case 2:
                        new_num=L(currnt_num);
                        new_op=current_op+"L";
                        break;
                    case 3:
                        new_num=R(currnt_num);
                        new_op=current_op+"R";
                        break;
                }
                if (visited[new_num]) continue; 
                // cout<< new_num<<"  "<<new_op<<endl;
                q.push(make_pair(new_num,new_op));
                visited[new_num]=true;
                if (new_num==dest){
                    cout<<new_op<<endl;
                    flag=false;
                }
            }
        }
    }

    return 0;
}