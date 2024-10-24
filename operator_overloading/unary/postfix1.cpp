//postfix operator 
#include <iostream>
using namespace std;

class Check
{
  private:
    int i;
  public:
    Check(){
        i=0;
    }
    //prefix
    Check operator ++ ()
    {
        Check temp;
        temp.i = ++i;
        return temp;
    }
//postfix
    // Notice int inside barcket which indicates postfix increment.
    Check operator ++ (int)
    {
        Check temp;
        temp.i = i++;
        return temp;
    }

    void Display()
    { cout << "i = "<< i <<endl; }
};

int main()
{
    Check obj, obj1;    
    obj.Display(); 
    obj1.Display();
    cout<<endl;

    // Operator function is called, only then value of obj is assigned to obj1
    obj1 = ++obj;
    obj.Display();
    obj1.Display();
    
    cout<<endl;

    // Assigns value of obj to obj1, only then operator function is called.
    obj1 = obj++;
    obj.Display();
    obj1.Display();
    
    cout<<endl;

    return 0;
}