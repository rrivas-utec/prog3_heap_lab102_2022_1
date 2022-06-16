#include <iostream>
#include "heap.h"

int main() {
    heap<int> h1;
//    cout << h1.size() << endl;
//    cout << boolalpha << h1.empty() << endl;

    h1.push(1);
    h1.push(12);
    h1.push(31);
    h1.push(4);

//    cout << h1.size() << endl;

    while(!h1.empty()) {
        cout << h1.top() << endl;
        h1.pop();
    }

    return 0;
}
