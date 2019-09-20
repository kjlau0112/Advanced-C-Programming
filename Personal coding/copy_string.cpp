#include <iostream>
#include <string.h>
using namespace std;

void someFunction(char*somePtr, char*anotherPtr,int arrLength)
{
        for(int i =0;i <arrLength; i++)
        {
            somePtr[i] = anotherPtr[i];
        }
        somePtr[arrLength] = '\0';
}

main()
{
    char array[6] = {'s','o','h','a','i','\0'};
    char someArr[] ={'\0'};

    int arrsize = strlen(array);

    // for(int i =0;i <arrsize; i++)
    // {
    //     someArr[i] =array[i];
    // }
    // someArr[arrsize] ='\0' ;

    // for(int i =0;i <arrsize; i++)
    // {
    //     cout<<someArr[i]<<endl;
    // }
    someFunction(someArr,array,arrsize);
    for(int i =0;i <arrsize; i++)
    {
        cout<<someArr[i]<<endl;
    }
}

