#include<iostream>
using namespace std;

int BubbleSort(int arr[], int n){
    int temp = 0;
    for (int k =0; k<n-1; k++){
        for(int i = 0; i<n-k-1; i++){
        int j = i + 1;
        if(arr[i] > arr[j]){
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
        else{
            continue;
        }
        j++;
        }
    }
    cout << "Sorted Array : " << endl;

    for(int i = 0; i<n; i++){
        cout<< arr[i] << " ";
    }
    }
int main(){

    int arr[6] = {10,1,7,6,14,9};
    cout<< BubbleSort(arr, 6);

} 
