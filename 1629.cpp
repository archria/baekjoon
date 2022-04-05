#include <iostream>

using namespace std;

long long solve(long long a, long long b, long long m){
    if(b == 0) return 1;
    long long val = solve(a,b/2,m);
    val = val * val % m;

    if(b % 2 == 0) return val;
    else
        return (val * a) % m;
}

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    
    cout<<a;

    return 0;
}