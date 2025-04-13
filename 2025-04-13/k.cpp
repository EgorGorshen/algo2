#include <cstddef>
#include <iostream>
#include <vector>
int main() {
    size_t n = 0;
    std::cin >> n;
    std::vector<size_t> gr(n, 0);
    bool v = false;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> v;
            if (i == j && v)
                gr[i] += 2;
            else
                gr[i] += v;
        }
    }

    for (size_t i = 0; i < n; ++i) {
        std::cout << gr[i] << std::endl;
    }

    return 0;
}
