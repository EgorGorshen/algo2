#include <cstddef>
#include <iostream>
int main() {
    size_t n = 0;
    std::cin >> n;
    int c = 0;
    int count = 0;
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> c;
            count += c;
        }
    }

    std::cout << count / 2;
    return 0;
}
