#include <cstddef>
#include <iostream>

int main() {
    size_t n = 0;
    std::cin >> n;
    bool v = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> v;
            if (i == j && v) {
                std::cout << "YES";
                return 0;
            }
        }
    }
    std::cout << "NO";
    return 0;
}
