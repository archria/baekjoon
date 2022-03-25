#include <iostream>

using namespace std;

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    for(int i = 0; i < b ; i++){
        a *= a;
        a = a%c;
    }
    cout<<a;

    return 0;
}