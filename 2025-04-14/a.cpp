#include <cstddef>
#include <iostream>
int main() {
    size_t n = 0;
    std::cin >> n;
    size_t count = 0;
    bool v = false;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> v;
            count += v;
        }
    }

    std::cout << count / 2;
    return 0;
}
