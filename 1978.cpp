#include <iostream>
#include <math.h>
using namespace std;

int GCD(int a, int b){
    if(b == 0) return a;
    else return GCD(b, a%b);
}

bool primeNum(int n){
    bool isPrime = true;
    for(int i = 1; i <= sqrt(n); i++){
        if(GCD(n,i) != 1){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    int ans = 0;
    cin>>n;
    for(int i = 0; i < n ; i++){
        int a;
        cin>>a;
        if(a != 1 && primeNum(a) == true)
            ans++;
    }
    cout<<ans;

    return 0;
}