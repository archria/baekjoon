#include <iostream>
#define PI 3.14159265358979
using namespace std;

int main(){
    double R;
    cin>>R;
    cout<<fixed;
    cout.precision(6);
    cout<<R*R*PI<<"\n";
    cout<<R*R*2;
    return 0;
}