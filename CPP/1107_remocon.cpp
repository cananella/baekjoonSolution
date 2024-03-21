#include<iostream>

using namespace std;
bool stop_btn[10]={false,};

bool is_possible(int num){
    string s = to_string(num);
	for (int i = 0; i < s.size(); i++) {
		if (stop_btn[s[i] - 48])
			return false;
	}
	return true;
}




int main(){
    int ch,m;
    cin>>ch>>m;
    for (int i=0;i<m;i++) {
        int d;
        cin>>d;
        stop_btn[d]=true;
    }
    if(ch==100){
        cout<<0;
        return 0;
    }

    int ans=abs(ch-100);

    int neer_num=ch;
    int cnt=0;

    for (int i=0;i <= 1000000;i++){
        if(is_possible(i)){
            int temp= abs(ch-i)+to_string(i).size();
            ans=min(ans,temp);
        }
    }
    cout<<ans;


    return 0;
}