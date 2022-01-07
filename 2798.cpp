#include <iostream>

using namespace std;

int main(){
    int n,m,diff;
    cin>>n;
    cin>>m;
    diff = -m;
    int ans = 0;
    int *nums = new int[n];
    for(int i = 0; i < n; i++){
        cin>>nums[i];
    }
    for(int i = 0 ; i < n-2 ; i++){
        for(int j = i+1; j < n-1 ; j++){
            for(int k = j+1; k < n ; k++){
                if((nums[i] + nums[j] + nums[k] - m) > diff && (nums[i]+nums[j] + nums[k]) <= m){
                    diff = nums[i] + nums[j] + nums[k] - m;
                    ans = nums[i] + nums[j] + nums[k];
                }
            }
        }
    }
    cout<<ans;
    return 0;
}