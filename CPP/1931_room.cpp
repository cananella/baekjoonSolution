#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector <pair<int,int>> time_list;

    for(int i=0; i<n;i++){
        int st,et;
        scanf("%d %d",&st,&et);
        time_list.push_back(make_pair(et,st));
    }
    sort(time_list.begin(),time_list.end());
    int time = time_list[0].first;
    int room_cnt=1;
    for( int i =1; i<n;i++){
        if(time<=time_list[i].second){
            room_cnt ++;
            time= time_list[i].first;
        }
    }
    cout<<room_cnt;


    // debug
    // while(!time_list.empty()){
    //     cout<<time_list.back().first<<" "<<time_list.back().second<<endl;
    //     time_list.pop_back();
    // }


    return 0;
}
