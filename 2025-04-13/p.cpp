#include <cstddef>
#include <iostream>
#include <vector>
int main() {
    size_t n = 0;
    size_t m = 0;
    std::cin >> n >> m;
    std::vector<size_t> gr(n, 0);

    size_t from_ = 0;
    size_t to_ = 0;

    for (size_t i = 0; i < m; ++i) {
        std::cin >> from_ >> to_;
        from_--;
        to_--;
        ++gr[from_];
        ++gr[to_];
    }

    size_t v = gr[0];
    for (size_t i = 0; i < n; ++i) {
        if (gr[i] != v) {
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
    return 0;
}
