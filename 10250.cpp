#include <iostream>

using namespace std;

int main(){
    int t,h,w,n;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>h;
        cin>>w;
        cin>>n;
        int a = n%h;
        int b = n/h;
        if(a != 0) b++;
        if(a == 0) a = h;
        a *= 100;
        int ans = a+b;
        cout<<ans<<endl;
    }
    return 0;
}