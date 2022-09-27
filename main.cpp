#include <iostream>

class Entity {
private:
    std::string name;
public:
    Entity(std::string name): name(name) {
        std::cout << "Created entity named " << name << std::endl;
    }
};

Entity* CreateEntityOnStack() {
    Entity e = Entity("entity");
    return &e;  // deallocated immediately when out of this function scope. because of stack variable.
}

Entity* CreateEntityOnHeap() {
    Entity* e = new Entity("entity1");
    return e;  // not deallocated until use delete keyword. because of heap variable.
}

int main() {
    Entity* e = CreateEntityOnStack();  // NULL
    Entity* e1 = CreateEntityOnHeap();  // 0x1037050
    delete e1;

    return 0;
}
