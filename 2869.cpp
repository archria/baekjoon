#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a,b,v;
    cin>>a;
    cin>>b;
    cin>>v;

    if( (v-b) % (a-b) != 0 )
        cout<< (v-b)/(a-b) + 1;
    else
        cout<< (v-b)/(a-b);
    return 0;
}