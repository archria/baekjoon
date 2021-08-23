#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,status = 0,score = 0;
    cin>>N;
    string *str = new string[N];
    for(int i = 0; i < N; i++){
        cin>>str[i];
    }
    for(int i = 0; i < N; i++){
        status = 0;
        score = 0;
        for(int j = 0; j < str[i].length(); j++){
            if(str[i][j] == 'O'){
                status++;
                score += status;
            }
            else if(str[i][j] == 'X'){
                status = 0;
            }

        }
        cout<<score<<endl;
    }

    return 0;
}