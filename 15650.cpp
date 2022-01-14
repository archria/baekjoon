#include <iostream>

using namespace std;

int tempStack[9] = {0};
bool P[9] = {false};

void printLoop(int n,int m, int loop, bool P[9], int lastNum){
    if(m == loop){
        for(int i = 0; i < m ; i++){
            cout<<tempStack[i]<<' ';
        }
        cout<<"\n";
    }
    else for(int i = lastNum; i <= n ; i++){
        if(P[i] == false){
            P[i] = true;
            tempStack[loop] = i;
            printLoop(n,m,loop+1,P,i+1);
            P[i] = false;
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    printLoop(n,m,0,P,1);
    return 0;
}