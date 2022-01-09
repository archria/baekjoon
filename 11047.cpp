#include <iostream>

using namespace std;

int main(){
    int n,k;

    cin>>n; cin>>k;
    int *coins = new int[n];
    for(int i = 0; i < n ; i++){
        cin>>coins[i];
    }
    int ans = 0;
    int coinNum = n-1;
    while(true){
        if(k >= coins[coinNum]){
            k -= coins[coinNum];
            ans++;
        }
        else if(k < coins[coinNum]){
            coinNum--;
        }
        if(k == 0) break;
    }

    cout<<ans;
    return 0;
}