#include <iostream>
#include <string>

using namespace std;

class Breakfast {
private:
    string menu;
    int nrAlergens;

public:
    Breakfast(const string menu, int nrAlergens) : menu(menu), nrAlergens(nrAlergens)
	{
        cout << menu << " has " << nrAlergens<< " alergens." <<endl;
	}

    //calls default constructor
    Breakfast() = default;

    //deleted both copy constructor and copy assignment operator:
    Breakfast(const Breakfast&) = delete;
    Breakfast& operator = (const Breakfast&) = delete;
	
    //calls destructor
    ~Breakfast()
	{
	    cout<< menu << "has been destroyed" << endl;
	}
	
    void get()
	{
	  cout<<"("<<menu<<"; "<<nrAlergens<<(")")<<endl;
	}
};

int main() 
{
    //For the last item I commented the code that would not work with the constructors disabled
        
    Breakfast EnglishBreakfast("Sausages, beans and eggs", 1);
    EnglishBreakfast.get();

    Breakfast default_Breakfast;//see if default constructor works
    //default_Breakfast = Breakfast("menu",0);
        
    // Breakfast AnotherBreakfast = EnglishBreakfast;//see if copy constructor works
    //AnotherBreakfast.get();
	
    //Breakfast YetAnotherBreakfast = move(EnglishBreakfast);//if move constructor works
    //YetAnotherBreakfast.get();
	
	
    return 0;
}
