#include <iostream>
#include <string>

using namespace std;

int main(){
    string input;
    cin>>input;
    int howmany[26] = {0};
    int max = 0;
    char ans = 0;
    for(int i = 0 ; i < input.length(); i++){
        if(input[i] >= 'a')
            howmany[ input[i]-97 ] ++;
        else
            howmany[input[i] - 65] ++;
    }
    for(int i = 0; i < 26; i++){
        if(howmany[i] > max){
            max = howmany[i];
            ans = i;
        }
        else if(howmany[i] == max)
            ans = '?';
    }
    
    if(ans == '?')
        cout<<'?';
    else
        cout<<char(ans+65);
}