#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int *score = new int[n+1];
    int *dp = new int[n+1];
    for(int i = 1; i < n+1; i++){
        cin>>score[i];
    }
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = score[3] + max(score[1] , score[2]);
    for(int i = 4; i < n+1 ; i++){
        dp[i] = score[i] + max(dp[i-3] + score[i-1], dp[i-2]);
    }
    cout<< dp[n];
    return 0;
}  