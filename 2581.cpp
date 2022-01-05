#include <iostream>
#include <math.h>
using namespace std;

int GCD( int a, int b){
    if(b == 0) return a;
    else return GCD(b, a%b);
}

bool isPrime(int n){
    for(int i = 1; i <= n/2; i++){
        if(GCD(n,i) != 1)
            return false;
    }
    return true;
}

int main(){
    int m,n;
    cin>>m;
    cin>>n;
    int min = -1, ans = 0;
    for(int i = m ; i <= n ; i++){
        if(isPrime(i) == true){
            min = i;
            ans += min;
            break;
        }
    }
    if(min == -1){
        cout<<"-1";
        return 0;
    }
    else if(min < n){
        for(int i = min+1; i <= n; i++){
            if(isPrime(i) == true)
                ans += i;
        }
    }
    cout<<ans<<endl<<min;
    return 0;
}
