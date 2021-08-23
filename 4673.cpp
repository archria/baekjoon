#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
    bool checklist[10000] = {0};
    int N;
    for(int i = 0; i < 10000; i++){
        string temp = to_string(i);
        N = i;
        for(int j = 0; j < temp.length(); j++){
            N += temp[j] - 48;
        }
        if(N < 10000){
            checklist[N] = 1;
        }
    }
    for(int i = 0; i < 10000; i++){
        if(checklist[i] == 0 )
            cout<<i<<endl;
    }
}