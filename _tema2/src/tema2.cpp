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

int main() {
        
        Breakfast EnglishBreakfast("Sausages, beans and eggs", 1);
	EnglishBreakfast.get();

	Breakfast default_Breakfast;//see if default constructor works
        
        Breakfast AnotherBreakfast = EnglishBreakfast;//see if copy constructor works
        AnotherBreakfast.get();
	
        
        Breakfast YetAnotherBreakfast = move(EnglishBreakfast);//if move constructor works
        YetAnotherBreakfast.get();
	
	
    return 0;
}
