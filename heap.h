//
// Created by rudri on 6/15/2022.
//

#ifndef PROG3_HEAP_LAB102_2022_1_HEAP_H
#define PROG3_HEAP_LAB102_2022_1_HEAP_H
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

using index_t = int;
// 1. Funciones para recorrer el heap
auto get_left_index = [](index_t root_index) { return root_index * 2; };
auto get_right_index = [](index_t root_index) { return root_index * 2 + 1; };
inline index_t get_root_index(index_t current_index) { return current_index / 2; }

// 2. Para seleccionar el hijo o el padre para comparar
bool has_parent(index_t current_index) { return current_index / 2 != 0; }
bool has_children(index_t current_index, index_t last_index) {
    return get_left_index(current_index) <= last_index;
}
bool has_right_child(index_t current_index, index_t last_index) {
    return get_right_index(current_index) <= last_index;
}

// 3. Seleccionar el hijo
template<typename Container>
index_t get_selected_child(const Container& cnt, index_t current_index) {
    if (!has_right_child(current_index, std::size(cnt) - 1))
            return get_left_index(current_index);

    auto left_index = get_left_index(current_index);
    auto right_index = get_right_index(current_index);

    return cnt[left_index] > cnt[right_index]? left_index: right_index;
}

// 4. implementar el percolate up
template<typename Container>
void percolate_up(Container& cnt, index_t current_index) {
    // Ubicar el índice de la raiz inmediata
    auto root_index = get_root_index(current_index);


    // Condiciones Base de Recursividad
        // a. Si no tiene padre se detiene
        if (!has_parent(current_index)) return;
        // b. (Max heap) si el padre es mayor detenerse
        if (cnt[root_index] > cnt[current_index]) return;

    // Intercambio de valores entre el padre y el hijo
    swap(cnt[root_index], cnt[current_index]);

    // Condición Recursiva de ubicarse en el padre y llamar al percolate_up
    percolate_up(cnt, root_index);
}

// 5. implementar el percolate down
template<typename Container>
void percolate_down(Container& cnt, index_t current_index) {
    // Obtener el sub-índice del hijo mayor
    auto selected_index = get_selected_child(cnt, current_index);

    // Condiciones bases
        // a. Si no tiene hijos se detiene
        if (!has_children(current_index, std::size(cnt) - 1)) return;
        // b. Si el valor actual es mayor que del hijo detenerse
        if (cnt[current_index]> cnt[selected_index]) return;

    // Intercambio de valores entre el padre y el hijo
    swap(cnt[current_index], cnt[selected_index]);

    // Condición recursiva de ubicarse en el hijo y llamar al percolate_down
    percolate_down(cnt, selected_index);
}

template<typename Container>
void heapify(Container& cnt) {
    // Ir al padre del ultimo
    auto current_index = get_root_index(std::size(cnt) - 1);
    while (current_index > 0) {
        percolate_down(cnt, current_index, std::size(cnt) - 1);
        --current_index; // ir al anterior
    }
}

template <typename T>
class heap {
    vector<T> data;
public:
    heap(): data(1) {}
    T top() { return data[1]; }
    bool empty() { return std::size(data) == 1; }
    int size() { return std::size(data) - 1; }
    void push(T value) {
        // Insertar al final
        data.push_back(value);
        // Ejecutar el percolate up
        percolate_up(data, std::size(data) - 1);
    }
    void pop() {
        // Validacion de vacio
        if (empty()) return;
        // Intercambio entre el primero y el ultimo
        swap(data[1], data.back());
        data.pop_back();
        // Ejecutar el percolate up
        percolate_down(data, 1);
    }
};

#endif //PROG3_HEAP_LAB102_2022_1_HEAP_H
