/*To calculate majority element in array using Moore's Voting Algorithm
Majority Element is the element that appears more than n/2(n=size of array) times in the array
Time complexity O(n) 
*/
#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>nums){
    int freq=0,ans=0;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(freq==0){
            ans=nums[i];
        }
        if(ans==nums[i]){
            freq++;

        }else{
            freq--;
        }
    }
    int count=0;
    for(int val:nums){
        if(val==ans){
            count++;
        }
    }
    if(count>n/2){
        return ans;
    }else{
        return -1;
    }

    return ans;
}

int main(){
    vector<int> nums={1,2,2,1,1};

    int ans=majorityElement(nums);
    cout<< "Majority Element="<< ans<< endl;
    return 0;
}