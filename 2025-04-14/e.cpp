#include <iostream>
#include <queue>
#include <vector>

int bfs(int start, const std::vector<std::vector<int>>& gr, int& farthest) {
    std::vector<int> dist(gr.size(), -1);
    std::queue<int> q;

    dist[start] = 0;
    q.push(start);
    int mx = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : gr[u]) {
            if (dist[v] != -1) {
                continue;
            }
            dist[v] = dist[u] + 1;
            q.push(v);
            if (dist[v] > mx) {
                mx = dist[v];
                farthest = v;
            }
        }
    }
    return mx;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> gr(n);

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    int farthest = 0;
    bfs(0, gr, farthest);
    int diameter = bfs(farthest, gr, farthest);

    std::cout << diameter + 1;

    return 0;
}
