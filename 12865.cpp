#include <iostream>

using namespace std;
int bag[100001][10] = {0,};
int main(){
    int N,K;
    cin>>N>>K;
    int weight[101];
    int item[101];
    for(int i = 1; i <= N ; i++){
        cin>>weight[i]>>item[i];
    }
    
    for(int i = 1; i <= N ; i++){ // i는 아이템
        for(int j = 1; j <= K ; j++){ // j 는 늘어나는 무게
            if(j >= weight[i]){
                bag[j][i] = max(bag[j][i-1], bag[j-weight[i]][i-1] + item[i]);
            }
            else{
                bag[j][i] = bag[j][i-1];
            }
        }
    }
    cout<<bag[K][N];

    return 0;
}