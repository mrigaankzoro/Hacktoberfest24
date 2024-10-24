//decrement postfix and prefix
//khudse
#include<iostream>
using namespace std;

class opt {
    int a;
    public:
    opt(int b){
      a=b;
    }

    opt(){
        a=0;

    }
    void showdata(){
        cout<<"a is"<<a<<endl;
    }



    opt operator --(){
        opt temp;
       
        temp.a=--a;
        return temp;

    }

    
    opt operator -- (int){
        opt temp;
       
        temp.a=a--;
        return temp;
        
    }

};

int main(){
    opt o1(4),o2;
    o1.showdata();
    o2.showdata();
    cout<<endl;

o2= --o1;
cout<<"after prefix operation"<<endl;
    o1.showdata();
    o2.showdata();
    cout<<endl;


o2 = o1--;
cout<<"after postfix operation"<<endl;
    o1.showdata();
    o2.showdata();
    cout<<endl;
    return 0;

    }