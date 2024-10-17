#include <iostream>
using namespace std;

void printname(int i, int n){
    if(i>n){
        return;
    }
    cout << "Siddhant" << endl;
    printname(i+1,n);
}

int main(){
    int n;
    cout << " enter the number : " << endl;
    cin >> n;

    printname(1,n);
}