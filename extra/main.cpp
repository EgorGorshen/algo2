#include <iostream>
#include <vector>

bool on_segment(std::pair<int, int>& p, std::pair<int, int>& a,
                std::pair<int, int>& b) {
    int min_x = std::min(a.first, b.first);
    int max_x = std::max(a.first, b.first);
    int min_y = std::min(a.second, b.second);
    int max_y = std::max(a.second, b.second);
    long long cross = (b.first - a.first) * (p.second - a.second) -
                      (b.second - a.second) * (p.first - a.first);
    return cross == 0 && p.first >= min_x && p.first <= max_x &&
           p.second >= min_y && p.second <= max_y;
}

int main() {
    int n, x, y;
    std::cin >> n >> x >> y;
    std::pair<int, int> pt = {x, y};

    std::vector<std::pair<int, int>> poly(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> poly[i].first >> poly[i].second;
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        std::pair<int, int>& a = poly[i];
        std::pair<int, int>& b = poly[(i + 1) % n];

        if (on_segment(pt, a, b)) {
            std::cout << "YES\n";
            return 0;
        }

        int y1 = a.second;
        int y2 = b.second;
        int x1 = a.first;
        int x2 = b.first;

        if ((y1 <= y && y2 > y) || (y2 <= y && y1 > y)) {
            long long x_int = 1LL * (x2 - x1) * (y - y1) + 1LL * x1 * (y2 - y1);
            if (x_int > 1LL * (y2 - y1) * x) {
                ++cnt;
            }
        }
    }

    if (cnt % 2 == 1) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    return 0;
}
