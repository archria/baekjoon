#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> dp(n);
    for(int i = 0; i < n ; i++){
        cin>>nums[i];
    }
    int ans = -1000;
    dp[0] = nums[0];
    for(int i = 1; i < n ; i++){
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
    }
    for(int i = 0; i < n ; i++){
        ans = max(ans, dp[i]);
    }
    cout<<ans;



    return 0;
}