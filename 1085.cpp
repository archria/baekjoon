#include <iostream>

using namespace std;

int main(){
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int len1 = 0, len2 = 0;
    w -= x;
    h -= y;
    if(w < x){
        len1 = w;
    }
    else{
        len1 = x;
    }

    if(h < y){
        len2 = h;
    }
    else{
        len2 = y;
    }
    if(len1 < len2){
        cout<<len1;
    }
    else{
        cout<<len2;
    }


    return 0;
}