#include <cstddef>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

typedef long long ll;

std::vector<size_t> bfs_diam() { return std::vector<size_t>(0); }

int main() {
    ll inf = 1000000000000000;
    int n, m, a, b;
    ll c;
    std::cin >> n >> m;  // n - кол-во вершин; m - кол-во рёбер
    std::vector<std::vector<std::pair<int, ll>>> country(
        n);  // в country[v] хранится пара (u, c), это означает, что из v есть
             // ребро в u веса c
    while (m--) {
        std::cin >> a >> b >> c;  // из вершины a идёт ребро в вершину b веса c
        a--;
        b--;
        country[a].push_back(std::make_pair(b, c));
    }
    std::vector<ll> dist(n, inf);
    dist[0] = 0;
    std::priority_queue<std::pair<ll, int>> q;
    q.push(std::make_pair(0, 0));
    while (!q.empty()) {
        ll len = -q.top().first;  // берёт максимальный элемент очереди. Так как
                                  // нам нужно минимальное расстояние, храним
                                  // расстояния умноженные на (-1)
        int i = q.top().second;
        q.pop();
        if (len > dist[i]) continue;
        for (auto X : country[i]) {
            if (dist[X.first] > dist[i] + X.second) {
                dist[X.first] = dist[i] + X.second;
                q.push(std::make_pair(-dist[X.first], X.first));
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::cout << dist[i] << " ";
    }
}
