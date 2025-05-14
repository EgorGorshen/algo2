#include <iostream>
#include <vector>

struct Flight {
    int from_;
    int dep;
    int to_;
    int arr;
};

int inf = 1e9 + 1;

int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    int k = 0;

    std::cin >> n >> a >> b >> k;
    --a;
    --b;

    std::vector<Flight> flight(k);
    for (auto& f : flight) {
        std::cin >> f.from_ >> f.dep >> f.to_ >> f.arr;
        --f.from_;
        --f.to_;
    }

    std::vector<int64_t> dp(n, inf);
    dp[a] = 0;

    bool flag = false;

    for (int i = 0; i < k; ++i) {
        flag = false;
        for (const auto& f : flight) {
            if (dp[f.from_] != inf && f.dep >= dp[f.from_]) {
                if (dp[f.to_] > f.arr) {
                    dp[f.to_] = f.arr;
                    flag = true;
                }
            }
        }
        if (!flag) break;
    }

    std::cout << dp[b];

    return 0;
}
