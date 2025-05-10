#include <algorithm>
#include <iostream>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    int from_ = 0;
    int to_ = 0;

    std::cin >> n >> from_ >> to_;
    --from_, --to_;

    std::vector<std::vector<int> > gr(n, std::vector<int>(n, 0));

    int val = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> val;
            std::cin >> gr[i][j];

            if (val == -1)
                gr[i][j] = inf;
            else
                gr[i][j] = val;
        }
    }

    std::vector<int> dist(n, inf);
    std::vector<int> parent(n, -1);
    std::vector<int> visited(n, false);

    dist[from_] = 0;

    while (true) {
        int cur = -1;
        for (int i = 0; i < n; ++i) {
            if (visited[i] || dist[i] == inf) continue;
            if (cur == -1 || dist[i] < dist[cur]) {
                cur = i;
            }
        }

        if (cur == -1) break;

        for (int node = 0; node < n; ++node) {
            if (gr[cur][node] == -1 || cur == node) continue;
            int d = gr[cur][node];
            if (dist[node] > dist[cur] + d) {
                dist[node] = dist[cur] + d;
                parent[node] = cur;
            }
        }
        visited[cur] = true;
    }
    if (dist[to_] == inf) {
        std::cout << -1;
    } else {
        std::vector<int> path;
        for (int v = to_; v != -1; v = parent[v]) {
            path.push_back(v + 1);
        }
        std::reverse(path.begin(), path.end());
        for (size_t i = 0; i < path.size(); ++i) {
            if (i != 0) std::cout << " ";
            std::cout << path[i];
        }
    }
    return 0;
}
