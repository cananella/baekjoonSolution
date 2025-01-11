#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    int N, D, K, C;
    cin >> N >> D >> K >> C;
    vector<int> sushi(N);
    vector<int> sushi_count(D+1, 0);
    deque<int> window;
    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }
    int count = 0;
    int max_count = 0;
    for (int i = 0; i < K; i++) {
        window.push_back(sushi[i]);
        if (sushi_count[sushi[i]] == 0) count++;
        sushi_count[sushi[i]]++;
    }
    max_count = count;

    for (int i = K; i < N + K; i++) {
        int sushi_out = window.front();
        window.pop_front();
        if (sushi_count[sushi_out] == 1) count--;
        sushi_count[sushi_out]--;
        int sushi_in = sushi[i % N];
        window.push_back(sushi_in);
        if (sushi_count[sushi_in] == 0) count++;
        sushi_count[sushi_in]++;
        if (sushi_count[C] == 0) max_count = max(max_count, count + 1);
        else max_count = max(max_count, count);
    }

    cout << max_count;

    return 0;
}