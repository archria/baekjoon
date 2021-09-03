#include <iostream>

using namespace std;

int main(){
    string input;
    cin>>input;
    int word = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == 'c' && input[i+1] == '=')
            i++;
        else if(input[i] == 'c' && input[i+1] == '-')
            i++;
        else if(input[i] == 'd' && input[i+1] == 'z' && input[i+2] == '=')
            i += 2;
        else if(input[i] == 'd' && input[i+1] == '-')
            i++;
        else if(input[i] == 'l' && input[i+1] =='j')
            i++;
        else if(input[i] == 'n' && input[i+1] == 'j')
            i++;
        else if(input[i] == 's' && input[i+1] == '=')
            i++;
        else if(input[i] == 'z' && input[i+1] == '=')
            i++;
        
        word++;
    }
    
    cout<<word;
    return 0;
}