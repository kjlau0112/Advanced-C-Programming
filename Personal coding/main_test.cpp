
#include<iostream> 
using namespace std; 

int *arrReturn()
{
   static int arr[3]= {1,2,3};
   return arr; 
}
void func();
int main() 
{ 
   int a =1;
   int b =2;
   int c= 3;
   if((a || b)&&c)
   {
      cout<<"a is "<<a<<endl;
   }
   int * p = arrReturn();

//cout<"printing"<<endl;
   for(int i = 0;i<3;i++)
   cout << *(p + i) << endl;
   cout<<sizeof(func())<<endl;

}

// #include <iostream>
// #include <ctime>

// using namespace std;

// function to generate and retrun random numbers.
// int * getRandom( ) {

//    static int  r[10];

//    // set the seed
//    //srand( (unsigned)time( NULL ) );
   
//    for (int i = 0; i < 10; ++i) 
//    {
//       r[i] = i;
//       cout << r[i] << endl;
//    }

//    return r;
// }

// // main function to call above defined function.
// int main () {

//    // a pointer to an int.
//    int *p;

//    p = getRandom();
   
//    for ( int i = 0; i < 10; i++ ) {
//       cout << "*(p + " << i << ") : ";
//       cout << *(p + i) << endl;
//    }

//    return 0;
// }