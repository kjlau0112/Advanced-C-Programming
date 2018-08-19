#include <iostream>
using namespace std;

void add(int a, int b)
{
   cout<<"a+b"<<a+b<<endl;
}
void subtract(int a, int b)
{
      cout<<"a-b"<<a-b<<endl;
}
void multiply(int a, int b)
{
      cout<<"a*b"<<a*b<<endl;
}

main()
{
	unsigned int ch, a = 15, b = 10;
	void(*fun_ptr_arr[])(int, int) = {add, subtract, multiply};
	cin>>ch;
	
	if(ch>2)
	{
		return 0;
	}
	(*fun_ptr_arr[ch])(15,10);
}
	
