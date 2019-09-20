#include <iostream>
using namespace std;


void process_arr(int *array, int arr_length, bool (*comparisonFcn)(int, int))
{
	int temp = 0;
	for (int currentIndex = 0; currentIndex < arr_length; currentIndex++)
	{
		for (int smallestIndex = 0; smallestIndex < arr_length-1; smallestIndex++)
		{
		//	if(array[smallestIndex]>array[smallestIndex+1])
		//	{
			if((*comparisonFcn)(array[smallestIndex],array[smallestIndex+1]))
			{
				temp =array[smallestIndex] ;
				array[smallestIndex] = array[smallestIndex+1];
				array[smallestIndex+1] = temp;
			}
		//	}
		}
	}

}

// Here is a comparison function that sorts in descending order
bool descending(int x, int y)
{
    return x < y; // swap if the second element is greater than the first
}

bool ascending(int x, int y)
{
    return x > y; // swap if the first element is greater than the second
} 

// This function prints out the values in the array
void printArray(int *array, int size)
{
    for (int index=0; index < size; ++index)
        std::cout << array[index] << " ";
    std::cout << '\n';
}


main()
{
	int length_of_arr =0;
	int arr[length_of_arr] = {};
	cout<<"defined length of array"<<endl;
	cin>> length_of_arr;
	
	cout<<"input the array"<<endl;
	for(int i =0; i<length_of_arr; i++)
	{
		cin>>arr[i];
		cout<<endl;
	}
	//int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
 
    // Sort the array in descending order using the descending() function
    process_arr(arr, length_of_arr, ascending);
    printArray(arr, length_of_arr);
 
	
}
