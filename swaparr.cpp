
#include <iostream>
using namespace std;

void reverse(int arr[], int i, int j){
    if(i>=j){
        return;
    }
    swap(arr[i], arr[j]);
    reverse(arr, i+1, j-1);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    reverse(arr, 0, 4);
    for(int i=0; i<5; i++){
        cout << arr[i] << " ";
    }
    return 0;
}