#include <iostream>
#include <queue>
#include <stack>
#include <variant>
#include <vector>

int main(int argc, char *argv[]) {
    int n = 0;
    std::cin >> n;

    // NOTE: Список смежности
    // std::vector<std::vector<int>> gr(n);
    // for (int i = 0; i < n; ++i) {
    //     int from_, to_;
    //     gr[from_].push_back(to_);
    // }

    // NOTE: Матрица смежности
    // std::vector<std::vector<bool>> gr(n, std::vector<bool>(n, false));
    // for (int i = 0; i < n; ++i) {
    //     int from_, to_;
    //     gr[from_][to_] = true;
    // }

    // NOTE: Список рёбер
    // int m = 0;
    // std::cin >> m;
    // std::vector<std::pair<int, int> > gr(m);
    // for (int i = 0; i < m; ++i) {
    //     int from_, to_;
    //     std::cin >> from_ >> to_;
    //     gr.push_back({from_, to_});
    // }

    // NOTE: DFS
    // std::stack<int> st;
    // std::vector<bool> visited(n);
    // st.push(0);
    // while (!st.empty()) {
    //     int node = st.top();
    //     st.pop();
    //     for (int i : gr[node]) {
    //         if (visited[i]) continue;
    //         visited[i] = true;
    //         st.push(i);
    //     }
    // }

    // NOTE: посик компонент связности
    // std::vector<bool> visited(n);
    // std::vector<int> component(n, -1);
    // int comp = 0;
    // for (int i = 0; i < n; ++i) {
    //     if (component[i] != -1) continue;
    //     ++comp;
    //     std::stack<int> st;
    //     st.push(i);
    //     while (!st.empty()) {
    //         int node = st.top();
    //         st.pop();
    //         for (int j : gr[node]) {
    //             if (component[j] != -1) continue;
    //             component[j] = comp;
    //             st.push(j);
    //         }
    //     }
    // }

    std::vector<bool> vis(n);
    std::stack<int> st;
    st.push(0);

    while (!st.empty()) {
    }

    return 0;
}
