#include <algorithm>
#include <iostream>
#include <vector>

const int64_t inf = 100000;

struct Edge {
    int from = 0;
    int to = 0;
    int64_t weight = 0;
};

int main() {
    int n = 0;
    std::cin >> n;
    int inf = 1e9;
    std::vector<Edge> edges;
    int x = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> x;
            if (x != 100000) {
                edges.push_back({i, j, x});
            }
        }
    }
    std::vector<bool> used(n, false);
    std::vector<int> ans;
    for (int s = 0; s < n; ++s) {
        ans.clear();
        if (!used[s]) {
            std::vector<int> dist(n, inf);
            std::vector<int> p(n, -1);
            dist[s] = 0;
            int c = -1;
            for (int i = 0; i < n; ++i) {
                c = -1;
                for (const Edge &cur : edges) {
                    if (dist[cur.to] > dist[cur.from] + cur.weight &&
                        dist[cur.from] != inf) {
                        used[cur.to] = true;
                        p[cur.to] = cur.from;
                        dist[cur.to] = dist[cur.from] + cur.weight;
                        c = cur.to;
                    }
                }
            }
            if (c != -1) {
                for (int i = 0; i < n; ++i) {
                    c = p[c];
                }
                for (int from = c;; from = p[from]) {
                    ans.push_back(from);
                    if (from == c && ans.size() > 1) break;
                }
                reverse(ans.begin(), ans.end());
            }
        }
        if (!ans.empty()) {
            std::cout << "YES" << "\n" << ans.size() << "\n";
            for (int i : ans) std::cout << i + 1 << " ";
            return 0;
        }
    }
    std::cout << "NO" << "\n";
}
