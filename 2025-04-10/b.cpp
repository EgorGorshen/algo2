#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

#define NODE std::pair<bool, bool>
#define LINE std::vector<NODE>
#define FIELD std::vector<LINE>

size_t walk(FIELD& f, size_t i, size_t j) {
    size_t count = 1;
    f[i][j].second = true;
    if (f[i + 1][j].first && !f[i + 1][j].second) {
        count += walk(f, i + 1, j);
    }
    if (f[i][j + 1].first && !f[i][j + 1].second) {
        count += walk(f, i, j + 1);
    }
    if (f[i - 1][j].first && !f[i - 1][j].second) {
        count += walk(f, i - 1, j);
    }
    if (f[i][j - 1].first && !f[i][j - 1].second) {
        count += walk(f, i, j - 1);
    }
    return count;
}

int main() {
    size_t n = 0;
    std::cin >> n;

    FIELD field(n, LINE(n, NODE(false, false)));

    char ch = ' ';
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cin >> ch;
            field[i][j] = NODE(ch == '.', false);
        }
    }
    size_t i = 0;
    size_t j = 0;

    std::cin >> i >> j;
    --i;
    --j;

    std::cout << walk(field, i, j);
    return 0;
}
