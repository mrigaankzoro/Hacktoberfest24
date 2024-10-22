//postfix operator using friend function

#include <iostream>
using namespace std;

class check
{
  private:
    int i;
  public:
    check(){
        i=0;
    }
    //prefix
     friend check operator ++ (check &);
    
    //postfix
    // Notice int inside barcket which indicates postfix increment.
     friend check operator ++ (check &,int);
    
    void Display()
    { cout << "i = "<< i <<endl; }
};

    check operator ++ (check & obj3)
    {
        check temp;
        temp.i = ++(obj3.i);
        return temp;
    }

    check operator ++ (check & obj3,int )
    {
        check temp;
        temp.i = obj3.i++;
        return temp;
    }


int main()
{
    check obj, obj1;    
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