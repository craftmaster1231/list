#include "List.h"
#include <string>
#include <list>

int main() {
    List<int> a(5);
    List <int> b = std::move(a);
}
