#include<iostream>

using namespace std;
// [종류][회전][y][x]
bool tetronimo[7][4][4][4]=
{
    {        
        {
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0}},
        {
            {1,1,1,1},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0},
            {1,0,0,0}}},

    {
        {
            {1,1,1,0},
            {0,1,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,0,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {0,0,0,0}},
        {
            {0,1,0,0},
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {0,1,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,0,0,0}}},

    {
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,1,0,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}}},

    {
        {
            {1,1,1,0},
            {1,0,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,1,0,0},
            {0,1,0,0},
            {0,1,0,0},
            {0,0,0,0}},
        {
            {0,0,1,0},
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,0,0,0},
            {1,0,0,0},
            {1,1,0,0},
            {0,0,0,0}}},
    {
        {
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,0,0,0}},
        {
            {0,1,1,0},
            {1,1,0,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,0,0,0},
            {1,1,0,0},
            {0,1,0,0},
            {0,0,0,0}}},
    
    {
        {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {0,0,0,0}},
        {
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {0,1,0,0},
            {1,1,0,0},
            {1,0,0,0},
            {0,0,0,0}}},
    {
        {
            {1,0,0,0},
            {1,1,1,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {1,1,0,0},
            {1,0,0,0},
            {1,0,0,0},
            {0,0,0,0}},
        {
            {1,1,1,0},
            {0,0,1,0},
            {0,0,0,0},
            {0,0,0,0}},
        {
            {0,1,0,0},
            {0,1,0,0},
            {1,1,0,0},
            {0,0,0,0}}}

        
};


int main(){
    int n , m;
    cin>>n>>m;
    int board[n+3][m+3] ;
    for(int i=0;i<n+3;i++)for(int j=0;j<m+3;j++) board[i][j]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    // for(int i=0;i<n+3;i++){
    //     for(int j=0;j<m+3;j++){
    //         cout<<board[i][j];
    //     }
    //     cout<<endl;
    // }
    int num_max=0;
    // int max_i,max_j,max_k,max_l;
    for(int i=0;i<n;i++){                    //board start y=>i
        for(int j=0;j<m;j++){                //board start x=>j

            for(int k=0;k<7;k++){            //브릭 종류=>K
                for(int l=0;l<4;l++){        //회전방향 =>l

                    int sum=0;
                    for(int o=0;o<4;o++){                    //board y=>i
                        for(int p=0;p<4;p++){                //board x=>j
                            if(tetronimo[k][l][o][p]) sum+=board[i+o][j+p];
                        }   
                    }
                    // cout<<sum<<endl;
                    if(sum>num_max) {
                        num_max=sum;
                        // max_i=i;
                        // max_j=j;
                        // max_k=k;
                        // max_l=l;
                    }
                }
            }
        }
    }
    // cout<<"start x,y,k,l "<<max_j<<" "<<max_i<<" "<<max_k<<" "<<max_l<<endl;
    cout<<num_max;
    

    return 0;
}