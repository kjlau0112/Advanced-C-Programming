#include <iostream>
using namespace std;

class someInterfaceBS
{
    public:
    virtual void printBS() = 0;
    virtual void wtfBS() = 0;
};

class generalBS
{
    public:
    someInterfaceBS *interfaceShitptr;
    generalBS(someInterfaceBS *interfaceptr)
    {};
};


class specificBS:public someInterfaceBS
{
    public:
    void printBS()
    {
        cout<<"specificBS called"<<endl;
    }

    void wtfBS()
    {
        cout<<"specificBS called"<<endl;
    }
    specificBS()
    {
        specificBS::printBS();
    }
};



main()
{
    generalBS * g_BS =new generalBS(new specificBS());

    delete g_BS;
}