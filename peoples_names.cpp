#include <iostream>
#include <string.h>
using namespace std;

void process_arr(char *individual_names, int arr_length)
{
	int temp;
	for (int currentIndex = 0; currentIndex < arr_length; currentIndex++)
	{
		for (int smallestIndex = 0; smallestIndex < arr_length-1; smallestIndex++)
		{
			if(individual_names[smallestIndex]>individual_names[smallestIndex+1])
			{
				temp =individual_names[smallestIndex] ;
				individual_names[smallestIndex] = individual_names[smallestIndex+1];
				individual_names[smallestIndex+1] = temp;
			}
		}
	}
}
main()
{
	
	int num_of_names;
	string name;
	string *peoples_names = NULL;
	char* mystring = NULL;
	
	cout << "How many names would you like to enter? ";
	cin >> num_of_names;
	cout << "Enter your name: ";
	peoples_names = new string[num_of_names];
	
	for (int j = 0; j < num_of_names; j++)
	{
		std::cout << "Enter name #" << j + 1 << ": ";
		std::cin >> peoples_names[j];
	
 
	//getline(cin, name); // name length
		cout << "There are " << peoples_names[j].length() << " letters in your name.\n";
		mystring = new char[peoples_names[j].length()] ;
	
		strcpy(mystring, peoples_names[j].c_str());
	
		process_arr(mystring, peoples_names[j].length());
		for (int i = 0; i < num_of_names; ++i)
		{
			cout << peoples_names[i];
			cout<<endl;
		}	
	}
	
	delete [] mystring;
	delete [] peoples_names;
	
	if(mystring == NULL)
	{
		cout<<"Array is not null"<<endl;
		//delete [] mystring;
		if(mystring != NULL)
		{
			cout<<"array is null now"<<endl;
		}
	}
}
