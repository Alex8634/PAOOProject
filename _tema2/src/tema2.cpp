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
	
	void get()
	{
	  cout<<"("<<menu<<"; "<<nrAlergens<<(")")<<endl;
	}
};

int main() {
        
        Breakfast EnglishBreakfast("Sausages, beans and eggs", 1);
	EnglishBreakfast.get();
        

    return 0;
}
