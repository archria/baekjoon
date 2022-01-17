#include <iostream>

using namespace std;

int n,m;
int tempStack[8];
void printLoop(int cnt){
    if(m == cnt){
        for(int i = 0; i < m ; i++){
            cout<<tempStack[i]<<" ";
        }
        cout<<"\n";
    }
    else{
        for(int i = 1; i <= n ; i++){
            tempStack[cnt] = i;
            printLoop(cnt+1);
        }
    }
}

int main(){
    cin>>n>>m;
    printLoop(0);
    return 0;
    
}