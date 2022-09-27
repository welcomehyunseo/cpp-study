#include <iostream>

class Spirit {
private:
    int age;
public:
    Spirit() {
        std::cout << "Age is " << age << std::endl;
    }

    Spirit(int age) {
        std::cout << "Age is " << age << std::endl;
        this->age = age;
    }
};

class Player {
private:
    std::string name;
    Spirit spirit;
public:
    Player(std::string name) {
        std::cout << "Name is " << name << std::endl;
        name = name;
        spirit = Spirit(0);
    }

    Player(std::string name, int age) :
            name(name),
            spirit(Spirit(age)
            ) {
        std::cout << "Name is " << name << std::endl;
    }

};

int main() {
    Player *p = new Player("player");
    delete p;


    std::cout << "\nIf member initializer lists used" << std::endl;
    Player *p1 = new Player("player1", 15);
    delete p1;

    return 0;
}
