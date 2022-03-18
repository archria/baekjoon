#include <iostream>

using namespace std;

int main(){
    int ans = 0;
    for(int i = 0; i < 5 ; i++){
        int a;
        cin>>a;
        ans += a*a;
    }
    cout<<ans%10;

    return 0;
}