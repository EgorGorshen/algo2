#include <algorithm>
#include <cstddef>
#include <iostream>
#include <vector>

int main() {
    size_t n = 0;
    std::cin >> n;

    std::vector<std::vector<bool>> gr(n, std::vector<bool>(n, false));
    bool v = false;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> v;
            gr[i][j] = v;
        }
    }

    std::vector<size_t> sources;
    std::vector<size_t> sinks;

    for (size_t i = 0; i < n; ++i) {
        bool is_source = true;
        for (int k = 0; k < n; ++k) {
            if (gr[k][i] != 0) {
                is_source = false;
                break;
            }
        }
        if (is_source) {
            sources.push_back(i + 1);
        }

        bool is_sink = true;
        for (int k = 0; k < n; ++k) {
            if (gr[i][k] != 0) {
                is_sink = false;
                break;
            }
        }
        if (is_sink) {
            sinks.push_back(i + 1);
        }
    }

    sort(sources.begin(), sources.end());
    sort(sinks.begin(), sinks.end());

    std::cout << sources.size() << std::endl;
    for (int s : sources) {
        std::cout << s << std::endl;
    }
    std::cout << sinks.size() << std::endl;
    for (int s : sinks) {
        std::cout << s << std::endl;
    }

    return 0;
}
