#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin>>n;
    if(n==1) { cout << "Not Prime\n"; return 0; }
    if(n==2 || n==3)  { cout << "Prime\n"; return 0; }
    if(n%2==0 || n%3==0)  { cout << "Not Prime\n"; return 0; }
    for(int i = 5; i*i <= n; i = i+6)
        if(n%i==0 || n%(i+2)==0)   { cout << "Not Prime\n"; return 0; }
     cout << "Prime\n"; return 0;
  }
