#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>

int main() {
    // 1. std::vector
    std::vector<int> vec = {10, 20, 30, 40, 50};
    std::cout << "Vector elements: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Modificar un elemento
    vec[2] = 100;
    std::cout << "Modified vector: ";
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 2. std::list
    std::list<int> lst = {10, 20, 30, 40, 50};
    std::cout << "List elements: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Insertar un elemento
    auto it_lst = lst.begin();
    std::advance(it_lst, 2);
    lst.insert(it_lst, 100);
    std::cout << "Modified list: ";
    for (int val : lst) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 3. std::deque
    std::deque<int> deq = {10, 20, 30, 40, 50};
    std::cout << "Deque elements: ";
    for (int val : deq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Añadir elementos al frente y al final
    deq.push_front(0);
    deq.push_back(60);
    std::cout << "Modified deque: ";
    for (int val : deq) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 4. std::set
    std::set<int> s = {30, 10, 20, 50, 40};
    std::cout << "Set elements: ";
    for (int val : s) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Añadir un elemento
    s.insert(25);
    std::cout << "Modified set: ";
    for (int val : s) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // 5. std::map
    std::map<int, std::string> m;
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";

    std::cout << "Map elements: ";
    for (const auto& pair : m) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;

    // Modificar un valor
    m[2] = "TWO";
    std::cout << "Modified map: ";
    for (const auto& pair : m) {
        std::cout << "{" << pair.first << ", " << pair.second << "} ";
    }
    std::cout << std::endl;

    return 0;
}
