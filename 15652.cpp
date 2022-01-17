#include <iostream>

using namespace std;

int n,m;
int tempStack[9];

void printLoop(int lastNum, int cnt){
    if(cnt == m){
        for(int i = 0; i < m ; i++){
            cout<<tempStack[i]<<" ";
        }
        cout<<"\n";
    }
    else for(int i = lastNum ; i <= n ; i++){
        tempStack[cnt] = i;
        printLoop(i,cnt+1);
    }
}

int main(){
    cin>>n>>m;
    printLoop(1,0);
    return 0;
}