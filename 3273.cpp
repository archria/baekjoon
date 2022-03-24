#include <iostream>
#include <algorithm>

using namespace std;

int n,x, cnt = 0;
int nums[100001];

int main(){
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>nums[i];
    }
    cin>>x;
    sort(nums,nums+n);
    int first = 0, last = n-1, sum;
    while(first < last){
        sum = nums[first] + nums[last];
        if(sum > x){
            last--;            
        }
        else if(sum < x){
            first++;
        }
        else{
            cnt++;
            last--;
        }
    }
    cout<<cnt;

    return 0;
}