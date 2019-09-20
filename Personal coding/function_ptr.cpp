#include <iostream>
using namespace std;


void printNumber(int x)
{
    
}

void printNumber(float x)
{
    
}

void HelloWorld()
{
    cout<<"Hello World"<<endl;
}

int interPara(int a)
{
    cout<<"inte a para"<<a<<endl;

    return a ;
}

main()
{ 
    typedef int (*intergerReturnFunc)(int);

    void(*kj)() = NULL;
    kj = HelloWorld;
    kj();

    int(*fptr)(int) = NULL;
    fptr = interPara;
    fptr(3); 

    intergerReturnFunc intgerReturnFunction = interPara;
    intgerReturnFunction(20);
} 