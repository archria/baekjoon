#include <iostream>
#include <string>

using namespace std;

int main(){
    int N;
    cin>>N;
    
    bool *tmp = new bool[N+1];
    for(int i = 0; i < N+1; i++){
        tmp[i] = true;
    }
    for(int i = 1; i <= N; i++){
        string temp = to_string(i);
        if(temp.length() == 1 || temp.length() == 2) 
            tmp[i] = true;
        else{ // if length >= 3 ? check start
            int * diff = new int[temp.length()];
            for(int j = 0; j < temp.length()-1; j++){
                diff[j] = temp[j] - temp[j+1];
            }
            for(int j = 0; j < temp.length()-2; j++){
                if(diff[j] != diff[j+1])
                    tmp[i] = false;
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i < N+1; i++){
        if(tmp[i] == true)
            cnt++;
    }
    cout<<cnt;
}