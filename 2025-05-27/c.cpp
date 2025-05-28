#include <algorithm>
#include <cstdint>
#include <iostream>

int64_t inf = -1e10;

struct Node {
    int begin = 0;
    int end = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    int64_t value = inf;
    int64_t max = inf;

    Node(int begin, int end) : begin(begin), end(end) {
        if (begin + 1 == end) return;
        int mid = (begin + end) / 2;
        left = new Node(begin, mid);
        right = new Node(mid, end);
        this->max = std::max(left->max, right->max);
    }

    void set(int index, int64_t value) {
        if (begin + 1 == end) {
            this->value = value;
            this->max = value;
            return;
        }
        if (index < left->end) {
            left->set(index, value);
        } else {
            right->set(index, value);
        }
        this->max = std::max(left->max, right->max);
    }

    int64_t get_max(int q_begin, int q_end) {
        if (q_begin <= begin && end <= q_end) {
            return max;
        }
        if (q_end <= begin || end <= q_begin) {
            return inf;
        }
        return std::max(left->get_max(q_begin, q_end),
                        right->get_max(q_begin, q_end));
    }
};

class Seg3 {
    Node* root = nullptr;

   public:
    Seg3(int begin, int end) { root = new Node(begin, end); }
    void set(int index, int64_t value) { root->set(index, value); }
    int64_t get_max(int q_begin, int q_end) {
        return root->get_max(q_begin, q_end);
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    Seg3 st(1, n + 1);
    for (int i = 1; i <= n; ++i) {
        int64_t v = 0;
        std::cin >> v;
        st.set(i, v);
    }
    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        char ch = 0;
        int a = 0, b = 0;
        std::cin >> ch >> a >> b;
        if (ch == 's') {
            std::cout << st.get_max(a, b + 1) << ' ';
        } else {
            st.set(a, b);
        }
    }
    return 0;
}
