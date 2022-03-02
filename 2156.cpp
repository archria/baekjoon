#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    n += 1;
    int *podoju = new int[n];
    int *dp = new int[n];
    dp[0] = 0;
    podoju[0] = 0;
    for(int i = 1; i < n ; i++){
        cin>>podoju[i];
    }
    dp[1] = podoju[1];
    dp[2] = podoju[1] + podoju[2];
    
    for(int i = 3; i < n ; i++){
        dp[i] = max(dp[i-1] , podoju[i] + max(dp[i-3] + podoju[i-1], dp[i-2]));
    }
    int ans = 0;
    for(int i = 1; i < n ; i++){
        ans = max(ans, dp[i]);
    }

    cout<<dp[n-1];

    return 0;
}