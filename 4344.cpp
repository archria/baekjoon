#include <iostream>

using namespace std;

int main(){
    int C,N;
    cin>>C;
    for(int i = 0; i < C; i++){
        cin>>N;
        double*score = new double[N];
        double all = 0, cnt = 0;
        double avg = 0,percent=0;
        for(int j = 0; j < N; j++){
            cin>>score[j];
        }
        for(int j = 0; j < N; j++){
            all += score[j];
        }
        avg = all / N;
        for(int j = 0; j < N; j++){
            if(score[j] > avg)
                cnt++;
        }
        percent = cnt / N * 100;
        cout<<fixed;
        cout.precision(3);
        cout<<percent<<"%"<<endl;
    }

}