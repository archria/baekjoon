#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> nums;
int n,m;
int findPlace(int target){
    int start = 0;
    int end = n-1;
    int mid;

    while(end >= start){
        mid = (end+start)/2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            end = mid-1;
        }
        else{
            start = mid + 1;
        }

    }
    return -1;
}



int main(){
    scanf("%d",&n);
    for(int i = 0; i < n ; i++){
        int a;
        scanf("%d",&a);
        nums.push_back(a);
    }
    sort(nums.begin(), nums.end());


    scanf("%d",&m);
    for(int i = 0; i < m ; i++){
        int a;
        scanf("%d",&a);
        if(findPlace(a) == -1)
            printf("0 ");
        else{
            
        }   
    }

    return 0;
}