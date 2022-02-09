#include <iostream>

using namespace std;

int gcd(int a, int b){
    int tmp, n;

    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b!=0){
        n = a%b;
        a = b;
        b = n;
    }
    return a;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        int a,b;
        cin>>a>>b;
        cout<<a*b/gcd(a,b)<<"\n";
    }

    return 0;
}