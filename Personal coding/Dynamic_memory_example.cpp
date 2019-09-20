#include <iostream>
#include <string.h>
using namespace std;

main()
{
	cout << "Enter your name: ";
	string name;
	getline(cin, name); // name length
	cout << "There are " << name.length() << " letters in your name.\n";
	
	char* mystring = new char[name.length()]  ;
	strcpy(mystring, name.c_str());
 	
 	 for (int i = 0; i < name.length(); ++i)
    {
        cout << mystring[i];
    }
    delete mystring;
}
