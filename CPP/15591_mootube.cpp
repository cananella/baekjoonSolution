#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<std::pair<int,int>>> list;
int n, q;

int BFS (int k, int v){
    int count = 0;
    std::vector<bool> visited (n, false);
    visited[v] = true;
    std::queue<std::pair<int,int>> q;
    q.push({v, k});
    
    while(!q.empty()){
        auto [node, usado] = q.front();
        q.pop();
        for(auto& elem: list[node]){
            auto [next_node, next_cost] = elem;
            if(!visited[next_node] && next_cost >= k){
                q.push(elem);
                visited[next_node] = true;
                count ++;
            }
        }
    }

    return count;
}

int main(){
    
    std::cin >> n >> q;
    list.resize(n, std::vector<std::pair<int,int>>());
    for(int i = 0 ; i < n - 1 ; i ++){
        int p, q, r;
        std::cin >> p >> q >> r;
        list[p - 1].push_back({q - 1,r});
        list[q - 1].push_back({p - 1,r});
    }

    for(int i = 0 ; i < q ; i ++){
        int k , v;
        std::cin >> k >> v;
        std::cout << BFS(k, v - 1) << "\n";
    }

    return 0;
}
