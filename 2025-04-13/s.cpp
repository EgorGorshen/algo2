#include <iostream>
#include <vector>

int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<bool> > gr(n, std::vector<bool>(n, false));

    for (size_t k = 0; k < m; ++k) {
        size_t a, b;
        std::cin >> a >> b;
        a--;
        b--;
        gr[a][b] = true;
        gr[b][a] = true;
    }

    for (size_t v = 0; v < n; ++v) {
        std::vector<size_t> gr_t;
        for (size_t u = 0; u < n; ++u) {
            if (u != v && gr[v][u]) {
                gr_t.push_back(u);
            }
        }

        for (size_t i = 0; i < gr_t.size(); ++i) {
            for (size_t j = i + 1; j < gr_t.size(); ++j) {
                size_t u = gr_t[i];
                size_t w = gr_t[j];
                if (!gr[u][w]) {
                    std::cout << "NO";
                    return 0;
                }
            }
        }
    }

    std::cout << "YES";
    return 0;
}
