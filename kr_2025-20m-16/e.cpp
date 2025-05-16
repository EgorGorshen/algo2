#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int inf = 1e9;

int main() {
    int n = 0;
    int k_ = 0;
    int ds = 0;
    int c = 0;
    std::cin >> n >> k_;

    std::vector<std::vector<int> > dist(n, std::vector<int>(n, inf));

    for (int i = 0; i < n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < k_; ++i) {
        int from_ = 0;
        int to_ = 0;
        int w = 0;
        std::cin >> from_ >> to_ >> w;
        --from_, --to_;
        dist[from_][to_] = std::min(dist[from_][to_], w);
    }

    for (int k = 0; k < n; ++k) {
        for (int from_ = 0; from_ < n; ++from_) {
            for (int to_ = 0; to_ < n; ++to_) {
                if (dist[from_][k] < inf && dist[k][to_] < inf)
                    dist[from_][to_] = std::min(dist[from_][to_],
                                                dist[from_][k] + dist[k][to_]);
            }
        }
    }

    for (int from_ = 0; from_ < n; ++from_) {
        for (int to_ = 0; to_ < n; ++to_) {
            if (from_ != to_ && dist[from_][to_] < inf) {
                ds += dist[from_][to_];
                ++c;
            }
        }
    }

    std::cout << std::fixed << std::setprecision(6);

    std::cout << static_cast<double>(ds) / c;

    return 0;
}
