#include <iostream>
#include <queue>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    int m = 0;

    std::cin >> n >> m;

    std::vector<int> whose(n);
    std::vector<std::vector<int>> gr(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> whose[i];
    }

    int from_ = 0;
    int to_ = 0;
    for (int i = 0; i < m; ++i) {
        std::cin >> from_ >> to_;
        --from_, --to_;
        gr[from_].push_back(to_);
        gr[to_].push_back(from_);
    }

    std::vector<int> path(n, -1);
    std::vector<int> dist(n, inf);
    std::vector<bool> visited(n, false);
    std::queue<int> que;
    que.push(0);
    dist[0] = 0;
    visited[0] = true;

    while (!que.empty()) {
        int node = que.front();
        que.pop();
        for (int i : gr[node]) {
            int duty = (whose[node] != whose[i]);
            if (dist[i] > dist[node] + duty) {
                dist[i] = dist[node] + duty;
                path[i] = node;

                if (!visited[i]) {
                    que.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    if (dist[n - 1] == inf) {
        std::cout << "impossible";
        return 0;
    }

    int node = n - 1;
    std::vector<int> pt;

    while (node != -1) {
        pt.push_back(node);
        node = path[node];
    }

    std::cout << dist[n - 1] << ' ' << pt.size() << std::endl;
    while (!pt.empty()) {
        std::cout << pt.back() + 1 << ' ';
        pt.pop_back();
    }

    return 0;
}
