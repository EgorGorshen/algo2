#include <cstddef>
#include <iostream>
int main() {
    size_t n = 0;
    std::cin >> n;
    bool v = false;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> v;
            if (v && (i < j)) {
                std::cout << i + 1 << ' ' << j + 1 << std::endl;
            }
        }
    }
    return 0;
}
