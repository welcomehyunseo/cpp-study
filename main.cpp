#include <iostream>

void* operator new(size_t size) {
    std::cout << "allocation " << size << " bytes" << std::endl;
    return malloc(size);
}

struct Object {
    int x, y, z;
};

int main() {
    Object* obj  = new Object{1, 2, 3};

    return 0;
}
