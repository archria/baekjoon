#include <iostream>

using namespace std;

int main(){
    bool x[1001] = {false};
    bool y[1001] = {false};
    for(int i = 0 ; i < 3 ; i++){
        int x1,y1;
        cin>>x1>>y1;
        if(x[x1] == false){
            x[x1] = true;
        }
        else if(x[x1] == true){
            x[x1] = false;
        }
        if(y[y1] == false){
            y[y1] = true;
        }
        else if(y[y1] == true){
            y[y1] = false;
        }
    }
    for(int i = 1; i < 1001; i++){
        if(x[i] == true){
            cout<<i<<" ";
            break;
        }
    }
    for(int i = 1; i < 1001; i++){
        if(y[i] == true){
            cout<<i;
            break;
        }
    }

    return 0;
}