#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

std::vector<std::vector<int>> g;
std::vector<int> d;

void bfs(int startV){
    std::fill(d.begin(),d.end(), -1);
    d[startV] = 0;
    std::queue<int> q;

    q.push(startV);

    while (!q.empty()){
        int v = q.front();
        q.pop();
        for (int u : g[v]){
            if (d[u] == -1){
                q.push(u);
                d[u] = d[v] + 1;
            }
        }
    }
}

int main(){
    int n,m;
    std::cin>>n>>m;
    g.resize(n);
    d.resize(n);
    for (int i = 0; i < m; i++){
        int v;
        int u;
        std::cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    int startV;
    std::cin >> startV;

    bfs(startV);

    for (int len : d){
        std::cout << len<<"\n";
    }

    return 0;
}
