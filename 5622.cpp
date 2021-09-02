#include <iostream>

using namespace std;

int main(){
   string inputCall;
    cin>>inputCall;
    int sum = 0;
    for(int i = 0 ; i < inputCall.length(); i++){
        if(inputCall[i] >= 'A' && inputCall[i] <= 'C')
            sum += 3;
        else if(inputCall[i] >= 'D' && inputCall[i] <= 'F')
            sum += 4;
        else if(inputCall[i] >= 'G' && inputCall[i] <= 'I')
            sum += 5;
        else if(inputCall[i] >= 'J' && inputCall[i] <= 'L')
            sum += 6;
        else if(inputCall[i] >= 'M' && inputCall[i] <= 'O')
            sum += 7;
        else if(inputCall[i] >= 'P' && inputCall[i] <= 'S')
            sum += 8;
        else if(inputCall[i] >= 'T' && inputCall[i] <= 'V')
            sum += 9;
        else if(inputCall[i] >= 'W' && inputCall[i] <= 'Z')
            sum += 10;
    } 
    cout<<sum;
}