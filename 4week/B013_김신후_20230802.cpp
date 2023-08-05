#include <iostream>
#include <set>

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    std::set<int> answer;
    std::set<std::pair<int, int>> visited;

    std::pair<int, int> initial_state = {0, C};
    std::set<std::pair<int, int>> queue;
    queue.insert(initial_state);

    while (!queue.empty()) {
        auto state = *queue.begin();
        queue.erase(queue.begin());

        int a = state.first;
        int c = state.second;

        int b = C - a - c;

        if (visited.count(state)) {
            continue;
        }
        visited.insert(state);

        answer.insert(c);

        // A to B
        if (a > 0 && b < B) {
            int amount = std::min(a, B - b);
            queue.insert({a - amount, c + amount});
        }

        // A to C
        if (a > 0 && c < C) {
            int amount = std::min(a, C - c);
            queue.insert({a - amount, c + amount});
        }

        // B to A
        if (b > 0 && a < A) {
            int amount = std::min(b, A - a);
            queue.insert({a + amount, c - amount});
        }

        // B to C
        if (b > 0 && c < C) {
            int amount = std::min(b, C - c);
            queue.insert({a, c + amount});
        }

        // C to A
        if (c > 0 && a < A) {
            int amount = std::min(c, A - a);
            queue.insert({a + amount, c - amount});
        }

        // C to B
        if (c > 0 && b < B) {
            int amount = std::min(c, B - b);
            queue.insert({a, c - amount});
        }
    }

    for (int ans : answer) {
        std::cout << ans << " ";
    }

    return 0;
}
