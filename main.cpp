#include <iostream>
#include <memory>

void* operator new(size_t size) {
    std::cout << "allocation " << size << " bytes" << std::endl;
    return malloc(size);
}

void operator delete(void* memory, size_t size) {
    std::cout << "Deallocation " << size << " bytes" << std::endl;
    free(memory);
}

struct Object {
    int x, y, z;
};

int main() {

    std::unique_ptr<Object> obj1 = std::make_unique<Object>();

    Object* obj = new Object{1, 2, 3};
    delete obj;

    return 0;
}
