#include <iostream>
#include <vector>

int inf = 30000;

struct Edge {
    int from;
    int to;
    int weight;

    Edge() : from(0), to(0), weight(0) {};
};

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<Edge> gr(m);
    std::vector<int> v(n + 1, inf);
    v[1] = 0;

    for (int i = 0; i < m; ++i) {
        std::cin >> gr[i].from >> gr[i].to >> gr[i].weight;
    }

    bool f = true;
    while (f) {
        f = false;
        for (int i = 0; i < m; ++i) {
            Edge cur_e = gr[i];
            if (v[cur_e.from] == inf && v[cur_e.to] == inf) {
                continue;
            }

            if (v[cur_e.to] > v[cur_e.from] + cur_e.weight) {
                v[cur_e.to] = v[cur_e.from] + cur_e.weight;
                f = true;
            }
        }
    }

    for (int i = 1; i < n + 1; ++i) {
        std::cout << v[i] << ' ';
    }

    return 0;
}
