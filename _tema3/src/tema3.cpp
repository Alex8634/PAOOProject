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
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        cout << "Person - " << name << "\n";
    }

    Person& operator=(const Person& other) {
        cout << "Assigning person operator: " << other.name << "\n";
        
        if (this == &other) {
            cout << "Assignment to self.\n";
            return *this;
        }

        delete[] name;
        name = new char[strlen(other.name) + 1];
        id = other.id;
        age = other.age;
        strcpy(name, other.name);

        return *this;
    }
    
    Person(const Person& other): id(other.id), age(other.age) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        cout << "Personal info copied." << "\n";
    }

    const int getID() const {
        return id;
    }
};

int main() {
    Person pers1(1, "Avram", 23);
    Person pers2(2, "Iancu", 34);
    
    cout << "Final id of pers1: " << pers1.getID() << "\n";
    cout << "Final id of pers2: " << pers2.getID() << "\n";
    
    Person pers3 = pers1;
    pers2 = pers1;
    pers1 = pers1;

    cout << "Final id of pers1: " << pers1.getID() << "\n";
    cout << "Final id of pers2: " << pers2.getID() << "\n";
    cout << "Final id of pers3: " << pers2.getID() << "\n";
    
    return 0;
}
