#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ans[501][501] = {0,};
    for(int i = 1; i <= n ; i++){
        for(int a = 1; a <= i ; a++){
            int temp;
            cin>>temp;
            ans[i][a] = max(temp + ans[i-1][a-1], temp+ans[i-1][a]);
        }
    }
    int mymax = 0;
    for(int i = 1; i <= n ; i++){
        if(ans[n][i] > mymax)
            mymax = ans[n][i];
    }
    cout<<mymax;
    return 0;
}