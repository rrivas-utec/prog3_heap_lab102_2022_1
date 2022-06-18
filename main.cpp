#include <iostream>
#include "heap.h"

struct point_t {
    int x = 0;
    int y = 0;
    point_t() = default;
    point_t(int x, int y): x(x), y(y) {}
    friend ostream& operator<<(ostream& os, const point_t& p) {
        os << "{" << p.x  << ", " << p.y << "}";
        return os;
    }
};

int main() {
    heap<int, vector, greater<>> h1;
    h1.push(1);
    h1.push(12);
    h1.push(31);
    h1.push(4);
    while(!h1.empty()) {
        cout << h1.top() << endl;
        h1.pop();
    }
    cout << "----\n";
    heap<int, vector, greater<>> h2 = {1, 20, 11, 12, 4, 25, 34, 2, 3};
    while(!h2.empty()) {
        cout << h2.top() << endl;
        h2.pop();
    }
    cout << "----\n";
    heap<int, vector, greater<>> h3 = {1, 20, 11, 12, 4, 25, 34, 2, 3};
    h3.replace(34, 5);
    while(!h3.empty()) {
        cout << h3.top() << endl;
        h3.pop();
    }

    auto compare_by_distance = [](auto a, auto b) {
        return (a.x * a.x) + (a.y * a.y) > (b.x * b.x) + (b.y * b.y);
    };

    heap<point_t, vector, decltype(compare_by_distance)> h4(compare_by_distance);
    h4.emplace(1, 1);
    h4.emplace(2, 2);
    h4.emplace(3, 3);
    while(!h4.empty()) {
        cout << h4.top() << endl;
        h4.pop();
    }

    return 0;
}
