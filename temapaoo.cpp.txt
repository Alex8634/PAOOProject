#include <iostream>

using namespace std;

class Country {
private:
    string* name;
    long* population;
    
public:
    Country(const string& name, long population)
    {
        this->name = new string(name);
        this->population = new long(population);
        cout << name << " has a population of " << population << endl;
    }
    
    //copy constructor
    Country(Country& aux)
    {
        this->name = aux.name;
        this->population = aux.population;
        cout << "copy constructor country"<< endl;
    }

    //move constructor
    Country(Country&& aux)
    {
        this->name = aux.name;
        this->population = aux.population;
        aux.name = nullptr;  
        aux.population = 0;       
        cout << "Move Constructor" << endl;
    }
    
    //Destructor
    ~Country()
    {
        delete name; 
        delete population;
        cout<<"Country for City called" << endl;
    }

    string getName() { 
        return *name; 
    }
    
    long getPopulation() { 
        return *population; 
    }
    
    void print_statement(){
        cout << *name << " is my favorite country!" << endl;
    }
    
};

class City {
private:
    string* name;
    long* population;
    int costOfLife;

public:
    City(const string& name, long population, int costOfLife)
    {
        this->name = new string(name);
        this->population = new long(population);
        cout << name << " has a population of " << population << " and a cost of living of "<< costOfLife << " euros" << endl;
    }
    
    //copy constructor
    City(City& aux)
    {
        this->name = aux.name;
        this->population = aux.population;
        costOfLife = aux.costOfLife;
        cout << "copy constructor city";
        cout << endl;
    }
    
    //move constructor
    City(City&& aux)
    {
        this->name = aux.name;
        this->population = aux.population;
        costOfLife = aux.costOfLife;
        aux.name = nullptr;  
        aux.population = 0;       
        cout << "Move Constructor" << endl;
    }

    //Destructor
    ~City()
    {
        delete name;
        delete population;
        cout<<"Destructor for City called";
        cout<<endl;  
    }
    
    int getCostOfLife() { 
        return costOfLife; 
    }
    
    void print_statement(){
        cout << *name << " is my favorite city!" << endl;
    }
};


int main() {
    Country country("Romania",20000000);
    country.print_statement();
    City city("Timisoara",500000, 650);
    city.print_statement();
    
    return 0;
}