#include <iostream>
#include "List.h"

int main() {

    std::cout << "Enter size of List: ";
    int size = 0;
    std::cin >> size;
    List<int> list(size);
    for( int i=0;i<size;i++){
        list[i] = i;
    }
    list.print();
    for (int i = 0; i < 5; i++) {
        std::cout << "Resize to: ";
        std::cin >> size;
        list.resize(size);
        list.print();
    }
    return 0;
}
