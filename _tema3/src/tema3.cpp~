#include <iostream>
#include <cstring>

using namespace std;

class Person {
private:
    int id;    
    char* name;  
    int age;

public:
    Person(int id, const char* name, int age): id(id), age(age) {
        this->name = new char[std::strlen(name) + 1];
        std::strcpy(this->name, name);
        std::cout << "Person - " << name << "\n";
    }

    Person& operator=(const Person& other) {
        std::cout << "Assigning person operator: " << other.name << "\n";
        
        if (this == &other) {
            std::cout << "Assignment to self.\n";
            return *this;
        }

        delete[] name;
        name = new char[std::strlen(other.name) + 1];
        id = other.id;
        age = other.age;
        strcpy(name, other.name);

        return *this;
    }

    const int getID() const {
        return id;
    }
};

int main() {
    Person pers1(1, "Avram", 23);
    Person pers2(2, "Iancu", 34);
    
    cout << "Final name of pers1: " << pers1.getID() << "\n";
    cout << "Final name of pers2: " << pers2.getID() << "\n";
    
    pers2 = pers1;

    pers1 = pers1;

    cout << "Final name of pers1: " << pers1.getID() << "\n";
    cout << "Final name of pers2: " << pers2.getID() << "\n";
    
    return 0;
}
