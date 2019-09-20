#include <iostream>
using namespace std;

main()
{
    int a=5;
    int b =3;
    //int &ref = b;
    int *ref = &a;
    cout <<"*ref is "<<*ref<<endl;
    *ref = 4;
    cout <<"*ref is "<<*ref<<endl;
    ref = &b;
    cout <<"*ref is "<<*ref<<endl;
    *ref =100;

    cout <<"a is "<<a<<endl;
    cout<<"b is "<<b<<endl;

    // ref = 8;

    // cout <<"a is "<<a<<endl;
    // cout<<"b is "<<b<<endl;
    // cout <<"ref is "<<ref<<endl;
}