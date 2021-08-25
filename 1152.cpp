#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    getline(cin,input);
    int cnt = 1;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == 32)
            cnt++;
    }
    if(input[0] == 32)
        cnt--;
    if(input[input.length()-1] == 32)
        cnt--;
    cout<<cnt;
}