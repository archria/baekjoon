#include <iostream>

using namespace std;

//오름차순을 방해하는 요소들을 찾아서 그것만 지워버리면 해결된다

int main(){
    int N;
    cin>>N;
    N += 1;
    int *A = new int[N];
    int *B = new int[N];
    int ans = 0;
    for(int i = 1; i < N ; i++){
        A[i] = 0;
    }
    for(int i = 1; i < N ; i++){
        int a,b;
        cin>>a>>b;
        A[a] = b;
        B[b] = a;
    }
    int temp = -1;
    for(int i = 1 ; i < N ; i++){
        if(A[i] != 0){
            if(A[i] > temp){
                temp = A[i];
            }
            else{
                temp = 
            }
        }
    }
    cout<<ans;

    return 0;
}