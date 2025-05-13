#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    int m = 0;
    std::cin >> n >> m;
    int from_ = 0;
    int to_ = 0;
    int w = 0;

    std::vector<std::vector<int>> weights(n, std::vector<int>(n, -1));
    std::vector<std::vector<int>> gr(n);
    std::vector<int> dist(n, inf);
    dist[0] = 0;

    for (int i = 0; i < m; ++i) {
        std::cin >> from_ >> to_ >> w;
        weights[from_][to_] = w;
        gr[from_].push_back(to_);
    }

    for

        return 0;
}
