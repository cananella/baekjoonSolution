#include<iostream>
#include<queue>

using namespace std;

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    queue <pair<int,int>> q;
    q.push(make_pair(n,0));
    bool visit[2*k]={false,};

    int min_cnt=abs(k-n);
    bool finish_triger=false;

    while(!q.empty()){
        int current_point = q.front().first;
        int current_cnt=q.front().second;
        q.pop();
        for(int i=0; i<3; i++){
            int new_p,new_cnt;
            switch(i){
                case 0:
                    new_p=current_point*2;
                    new_cnt=current_cnt;
                    break;

                case 1:
                    new_p=current_point-1;
                    new_cnt=current_cnt+1;
                    break;    

                case 2:
                    new_p=current_point+1;
                    new_cnt=current_cnt+1;
                    break;
                    
            }

            if(new_p<0||new_p>2*k) continue;
            if(visit[new_p]) continue;

            if (new_p==k&&min_cnt>new_cnt) {
                min_cnt=new_cnt;
                finish_triger=false;
            }
            if(new_p!=k) visit[new_p]=true;

            if(!finish_triger)q.push(make_pair(new_p,new_cnt));

            // cout<<new_p<<" "<<new_cnt<<endl;
        }
        // cout<<"\n";
    }
    cout<<min_cnt;
    return 0;
}