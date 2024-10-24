// adding 2 obj




#include <iostream>
using namespace std;

class no
{
  private:
    int num=0;
  public:
   no(){
        
    }

    no(int b ){
        num=b;
    }

    
    no operator +(no obj)
    {
       no temp;
       
       temp.num = num+(obj.num);

       return temp;
    }

    void Display()
    { cout << "number  = " << num << endl; }
};

int main()
{
    no obj2(5), obj1(4);
    obj2.Display();
    obj1.Display();
    no obj3;
    obj3.Display();
    obj3 = obj1 +obj2;

    obj2.Display();
    obj1.Display();
    obj3.Display();

    return 0;
}