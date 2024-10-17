#include <iostream>
using namespace std;

   void PrimesInRange(int lowBound, int upBound){
    for(int i = lowBound, into i <= upBound;i++){
      if(isPrime(i)){
        cout << (i) << endl;
      }
    }
  }

   bool isPrime(int a){
      for(int i = 2; i <= Math.sqrt(a);i++){
        if(a%i==0){
          return 1;
        }
      }
      return 0;
    }

  public static main(){
    int low = 0;
    int high = 20;
    PrimesInRange(low,high);
  }
