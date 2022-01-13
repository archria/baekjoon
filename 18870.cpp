#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> nums(N);
    
    for(int i = 0; i < N ; i++){
        cin>>nums[i];
    }
    vector<int> temp(nums);
    sort(nums.begin(),nums.end());
    nums.erase( unique(nums.begin(), nums.end()) , nums.end());
    for(int i = 0; i < N ; i++){
       auto tp = lower_bound(nums.begin(), nums.end(), temp[i]);
       cout<<tp-nums.begin()<<" ";
    }
    
    return 0;
}