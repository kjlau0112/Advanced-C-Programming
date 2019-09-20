#include <iostream> 
using namespace std;
 
class Shape 
{
   protected:
      int width, height;
      
   public:
      Shape( int a = 0, int b = 0)
      {
         width = a;
         height = b;
      }
      virtual int area() 
      {
         cout << "Parent class area :" <<endl;
         return 0;
      }

      void printStuff()
      {
         cout<<"Base class printt"<<endl;
      }
};

class Rectangle: public Shape 
{
   public:
      Rectangle( int a = 0, int b = 0):Shape(a, b) { }
      
      int area () 
      { 
         cout << "Rectangle class area :" <<(width * height)<<endl;
         return (width * height); 
      }
            
      void printStuff()
      {
         cout<<"Rec class printt"<<endl;
      }
};

class Triangle: public Shape 
{
   public:
      Triangle( int a = 0, int b = 0):Shape(a, b) { }
      
      int area () 
      { 
         cout << "Triangle class area :" <<(width * height / 2)<<endl;
         return (width * height / 2); 
      }

      void printStuff()
      {
         Shape::printStuff();
      }
};

// Main function for the program
main() {
   // Shape *shape;
   // Rectangle rec(10,7);
   // Triangle  tri(10,5);

   // // store the address of Rectangle
   // shape = &rec;
   
   // // call rectangle area.
   // shape->area();

   // // store the address of Triangle
   // shape = &tri;
   
   // // call triangle area.
   // shape->area();

   Triangle *triClassptr = new Triangle(20,5);
   triClassptr->printStuff();

   delete triClassptr;
   
   return 0;
}
//The concept of virtual func