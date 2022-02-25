#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int *dp = new int[n+1];
    dp[2] = dp[3] = 1;
    for(int i = 4; i <= n ; i++){
        if(i % 2 != 0 && i%3 != 0){
            dp[i] = dp[i-1] + 1;
        }
        else if(i%2 == 0 && i%3 == 0){
            dp[i] = 1 + min(dp[i/2], dp[i/3]);
        }
        else if(i%2 == 0){
            dp[i] = 1+ min(dp[i/2],dp[i-1]);
        }
        else if(i%3 == 0){
            dp[i] = 1+ min(dp[i/3],dp[i-1]);
        }
    }
    cout<<dp[n];

    return 0;
}