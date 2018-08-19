#include <iostream>
#include <string.h>
using namespace std;

main()
{
	string name;
	int names;
	char* mystring =NULL;

	cout<<"How many names is there"<<endl;
	cin>>names;
	string *peoples_names = new string[names];
	
	cout << "Enter your name: ";

	
	for (int j =0; j< names;j++)
	{
		cin>>peoples_names[j];
		cout << "There are " << peoples_names[j].length() << " letters in your name.\n";
		
	//	getline(cin, name); // name length
		mystring = new char[name.length()] ;
		strcpy(mystring, name.c_str());
	
		for (int i = 0; i < name.length(); ++i)
		{
			cout << mystring[i];
	
		}
	}
	cout<<endl;

	delete []  mystring;
}


