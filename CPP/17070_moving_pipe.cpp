#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int N;
std::vector<std::vector<int>> board;

std::vector<std::vector<std::tuple<int, int, int>>> moving ={
    {{0, 1, 0}, {1, 1, 1}},
    {{0, 1, 0}, {1, 1, 1}, {1, 0, 2}},
    {{1, 1, 1}, {1, 0, 2}}};

int main(){
    std::cin >> N;
    board.resize(N, std::vector<int>(N, 0));
    for(int i = 0; i < N ; i ++){
        for(int j = 0; j < N ; j ++){
            std::cin >> board[i][j];
        }
    }
    int result = 0;
    std::queue<std::tuple<int, int, int>> q;
    q.push({0, 1, 0});

    while(!q.empty()){
        auto[x, y, diagonal] = q.front();
        q.pop();
        if(x == N-1 && y == N -1){
            result ++;
            continue;
        }
        for(auto& [plus_x, plus_y, next_diagonal] : moving[diagonal]){
            if(x + plus_x >= N || y + plus_y >=N) continue;
            if(board[x + plus_x][y + plus_y]) continue;
            if(next_diagonal == 1 && (board[x + plus_x][y] || board[x][y + plus_y])) continue;
            q.push({x + plus_x, y + plus_y, next_diagonal});
        }
    }
    std::cout << result;

    return 0;
}