#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    while(true){
        int len[3];
        for(int i = 0; i < 3 ; i++){
            cin>>len[i];
        }
        sort(len,len+3);
        if(len[0] == 0 && len[1] == 0 && len[2] == 0){
            break;
        }
        else{
            if(len[0] * len[0] + len[1]*len[1] == len[2]*len[2]){
                cout<<"right\n";
            }
            else{
                cout<<"wrong\n";
            }
        }
    }
}