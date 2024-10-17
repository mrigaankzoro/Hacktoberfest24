#include <iostream>
using namespace std;

void printsum(int i, int sum){
    if(i<1){
        cout << sum << endl;
        return;
    }

    printsum(i-1,sum+i);
}

int main(){
    printsum(3, 0);
}