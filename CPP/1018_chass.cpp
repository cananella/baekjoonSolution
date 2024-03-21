#include<iostream>


using namespace std;

char wf_board[9][9] ={"WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW"};
char bf_board[9][9] ={"BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB",
                     "BWBWBWBW",
                     "WBWBWBWB"};

int chack_dff(char arr[8][8]){
    int w_dff=0;
    int b_dff=0;

    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]!=wf_board[i][j]) w_dff++;
            if(arr[i][j]!=bf_board[i][j]) b_dff++;
        }
    }
    return min(w_dff,b_dff);
}

void print_board(char arr[8][8]){
    cout<<endl;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

int main(){

    int n,m;
    scanf("%d %d",&n,&m);
    char board[n][m];
    char batch[8][8];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    int min_change=32;
    for(int i=0;i<=n-8;i++){
        for(int j=0;j<=m-8;j++){

            int dff=0;
            for(int k=0;k<8;k++){
                for(int l=0;l<8;l++){
                    batch[k][l]=board[i+k][j+l];
                }
            }

            dff=chack_dff(batch);
            if(min_change>dff) min_change=dff;


        }
    }

    
    cout<<min_change;

    return 0;
}