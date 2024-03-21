#include<iostream>
#include<cmath>

using namespace std;
int N,y,x;
int ans=0;

void dc(int nx , int ny , int size){
    // cout<< nx<<","<<ny<<"::"<<nx+size/2<<","<<ny+size/2<<endl;
    if(nx==x&&ny==y){
        cout<<ans;
        return ;
    }
    else if(x<nx+size&& y<ny+size&& x>=nx&&y>=ny){
        dc(nx       ,ny       ,size/2);
        dc(nx+size/2,ny       ,size/2);
        dc(nx       ,ny+size/2,size/2);
        dc(nx+size/2,ny+size/2,size/2);
    }
    else{
        ans+= size*size;
        // cout<< "ans is "<<ans<<endl;
    }
}


int main(){
    cin>>N>>y>>x;
    dc(0,0,pow(2,N));
    return 0;
}