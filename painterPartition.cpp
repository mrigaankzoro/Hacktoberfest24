/*
Problem Statement:
Given n boards of different lengths represented by an array arr of size n, and m painters, you need to determine the minimum amount of time required to paint all the boards. Each painter paints a contiguous segment of boards.

Constraints:

A painter can only paint continuous segments of boards.
Each painter takes the same amount of time to paint a unit length of the board.
You have to minimize the maximum time taken by a painter to paint their assigned boards.

Input:

An integer n representing the number of boards.
An integer m representing the number of painters.
An array arr[] of size n, where each element arr[i] represents the length of the i-th board.
*/
#include<iostream>
#include<vector>
using namespace std;

int rotatedSearch(vector<int>&nums, int target){
int st = 0, end = nums.size()-1;
while(st<=end){
    int mid = st + (end-st)/2;
    if(nums[mid]==target){
        return mid;
    }
    if(nums[st]<=nums[mid]){
          if(nums[st]<=target<=nums[mid]){
                 end = mid-1;
          }
          else{
              st = mid+1;
          }
    }
    else{
        if(nums[mid]<=target<=nums[end]){
             st = mid+1;
        }
        else{
            end = mid-1;
        }
    }
}
return -1;
}
int main(){
vector<int> v = {5,6,1,2,3,4};
cout<<rotatedSearch(v,3)<<endl;
}