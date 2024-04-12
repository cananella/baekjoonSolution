#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
vector<pair<long long,long long>> points;
int n;

long double cross(long long i, long long j){
    long double a = points[0].first, b = points[0].second;
	long double c = points[i].first, d = points[i].second;
	long double e = points[j].first, f = points[j].second;
	return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main(){
    cin>>n;
    for (int i =0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        points.push_back({a,b});
    }
    
    long double ans =0;
    for(int i=1;i< points.size()-1;i++){ 
        ans += cross(i,i+1);
    }
    printf("%.1Lf",abs(ans));
    return 0;
}