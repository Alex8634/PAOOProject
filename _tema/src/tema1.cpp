#include <iostream>

using namespace std;

class Country {
protected:
    string* name;
    long* population;
    
public:
    Country(const string& name, long population)
    {
        this->name = new string(name);
        this->population = new long(population);
        cout << name << " has a population of " << population << endl;
    }
    
    Country(Country& aux)
    {
        this->name = aux.name;
        this->population = aux.population;
        cout << "copy constructor country"<< endl;
    }
    
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

class City : public Country{
private:
    int costOfLife;

public:
    City(const string& name, long population, int costOfLife) : Country(name, population), costOfLife(costOfLife) 
    {
        cout << name << " has a population of " << population << " and a cost of living of "<< costOfLife << " euros" << endl;
    }
    
    /*City(City& aux)
    {
        this->name = aux.name;
        this->population = aux.population;
        costOfLife = aux.costOfLife;
        cout << "copy constructor city"<< endl;
    }*/
    
    ~City()
    {
        delete name;
        delete population;
        cout<<"Destructor for City called" << endl;
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
