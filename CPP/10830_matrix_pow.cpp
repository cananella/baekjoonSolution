#include <iostream>


using namespace std;
long long matrix[5][5];
long long temp_matrix[5][5];
long long ans_matrix[5][5];
long long n, b;


void Matrix_multi(long long x[5][5], long long y[5][5]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp_matrix[i][j]=0;
            for (int k=0; k<n;k++){
            temp_matrix[i][j]+=(x[i][k]*y[k][j]);        
            }

            temp_matrix[i][j] %=1000;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            x[i][j]=temp_matrix[i][j];
        }
    }
}

int main(){
    cin>>n>>b;
    int num;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>num;
            matrix[i][j]=num;
            ans_matrix[i][j]=0;
        }
        ans_matrix[i][i]=1;
    }


    while(b>0){
        if(b%2==1){
            Matrix_multi(ans_matrix,matrix);
        }
        Matrix_multi(matrix,matrix);
        b /=2;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ans_matrix[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}