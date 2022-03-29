#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    long long ans;
    ans = 1;
    for(int i = n ;  i > n-k ; i--){
        ans *= i;
        
    }
    for(int i = k ; i > 0 ; i--){
        ans  /= i;
    }
    cout<<ans;
    return 0;
}