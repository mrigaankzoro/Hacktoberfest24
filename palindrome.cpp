#include <bits/stdc++.h>
using namespace std;

bool palindrome(int arr[], int i, int n){
    if(i>n/2){
        return true;
    }
    
    if(arr[i]!=arr[n-i-1]){
        return 0;
    }
    
    palindrome(arr,i+1,n);  
}

int main(){
    int arr[6] = {1,2,3,8,2,1};
    cout << palindrome(arr, 0, 6);
}