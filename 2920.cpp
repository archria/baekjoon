#include <iostream>

using namespace std;

int main(){
    bool desc = false, asc = false;
    int a[8];
    for(int i = 0; i < 8 ; i++){
        cin>>a[i];
    }
    for(int i = 1; i < 8 ; i++){
        if(a[i] > a[i-1])
            asc = true;
        if(a[i] < a[i-1])
            desc = true;
    }
    if(asc == true && desc == true){
        cout<<"mixed";
    }
    else if(desc == true){
        cout<<"descending";
    }
    else{
        cout<<"ascending";
    }


    return 0;
}