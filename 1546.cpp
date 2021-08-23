#include <iostream>
using namespace std;

int main(){
    int N;
    double M;
    double sum = 0;
    cin>>N;
    double *score = new double[N];
    for(int i = 0; i < N; i++){
        cin>>score[i];
    }
    for(int i = 0; i < N; i++){ // max score scan
        if(score[i] > M)
            M = score[i];
    }
    for(int i = 0; i < N; i++){
        score[i] = score[i]/M*100;
    }
    for(int i = 0; i < N; i++){
        sum += score[i];
    }
    cout<<sum / N;
    

    return 0;
}