#include <iostream>

using namespace std;

int factorial(int N, int M){
    M = M * N;
    N = N-1;
    if(N == 0)
        return M;
    else
        return factorial(N,M);
}

int main(){
    int N;
    cin>>N;
    if(N == 0){
        cout<<"1";
        return 0;
    }
    cout<<factorial(N,1);
    return 0;
}