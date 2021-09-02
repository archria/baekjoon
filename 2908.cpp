#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(){
    string x,y;
    int a =0,b =0;
    cin>>x;
    cin>>y;
    for(int i = 0 ; i < 3; i++){
        a += (x[i]-'0') * pow(10,i);
        b += (y[i]-'0') * pow(10,i);
    }
    if(a > b)
        cout<<a;
    else
        cout<<b;

}