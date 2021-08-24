#include <iostream>
#include <stack>

using namespace std;

int main(){
    int N;
    string input;
    int sum = 0;
    cin>>N;
    cin>>input;
    for(int i =0 ; i< N; i++){
        sum += input[i] - 48;
    }
    cout<<sum;
}