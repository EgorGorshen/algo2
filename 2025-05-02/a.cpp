#include <iostream>
#include <set>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    std::cin >> n;
    std::vector<std::vector<std::pair<int, int>>> gr(n + 1);

    for (int i = 2; i <= n; ++i) {
        int p;
        std::cin >> p;
        gr[p].emplace_back(i, 1);
        gr[i].emplace_back(p, 1);
    }
    std::vector<int> dist(n + 1, inf);
    std::set<std::pair<int, int>> pq;

    dist[1] = 0;
    pq.insert({0, 1});
    int mx = 0;

    while (!pq.empty()) {
        int u = pq.begin()->second;
        int curd = pq.begin()->first;
        pq.erase(pq.begin());
        if (curd > mx) {
            mx = curd;
        }
        for (auto [v, w] : gr[u]) {
            if (dist[v] > dist[u] + w) {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
        }
    }
    std::vector<int> x;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == mx) {
            x.push_back(i);
        }
    }

    std::cout << mx << std::endl;
    std::cout << x.size() << std::endl;

    for (int node : x) {
        std::cout << node << ' ';
    }
    return 0;
}
