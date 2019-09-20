#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void power(int input,int*sq,int *cube,int*quad);
int main(int argc, char** argv) 
{
	int  number1,number2,number3,number4;
	cout<<"define a number"<<endl;
	cin>>number1;
	power(number1,&number2,&number3,&number4);
	cout<<number1<<endl<<number2<<endl<<number3<<endl<<number4<<endl;
	
	return 0;
}
void power(int input,int*sq,int *cube,int*quad)
{
	*sq=input*input;
	*cube=input*input*input;
	*quad=input*input*input*input;
}
