#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int abc = a*b*c;
    string stra = to_string(abc);
    int abcSize = stra.length();
    int ans[10] = { 0 };
    for(int i = abcSize-1; i >=0; i--){
        int a = abc / pow(10,i);
        abc -= a*pow(10,i);
        ans[a]++;

    }
    for(int i = 0 ; i < 10; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}