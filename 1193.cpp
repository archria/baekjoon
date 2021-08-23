#include <iostream>

using namespace std;

int diff = 0;
int where = 0; // X의 위치를 알아내기 위한 변수
int sum = 0; // 지금 대각선의 합을 계산
int X = 0;
int main(){
    cin>>X;
    for(int i = 1; i < 5000000; i++){ // what if X == 5?
        where += i;
        if(where >= X){ // count full -> exceed X
            where -=i;
            //cout<<"X : "<<X<<" where : "<<where<<endl;
            sum = i+1;
            break;
        }
    }
    diff = X - where;
    if(sum %2 == 1)
        cout<<diff<<'/'<<sum-diff;
    else
        cout<<sum - diff<<'/'<<diff;
    return 0;
}