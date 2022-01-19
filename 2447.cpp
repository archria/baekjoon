#include <iostream>
using namespace std;



void printStar(int i, int j, int n){
    if(i/n%3 == 1 && j/n%3 == 1){ // 가장 가운데의 빈 칸은 항상 1,1이다 (좌표계 0,1,2 / 0,1,2 로 이루어졌다고 가정함)
        cout<<" ";
    }
    else if(n/3 == 0){ // 가장 낮은 0,1,2 좌표계로 내려왔을 경우? (ex. 0~9를 0~2, 0~2, 0~2로 쪼갬.)
    // 1인지는 위에서 걸렀으므로 우리에게 필요한 것은 이 좌표계가 가장 하위 좌표계인지 확인하는 일
        cout<<"*";
    }
    else{
        printStar(i,j,n/3); // 가장 큰 경우를 검사했으니 하위 좌표계로 들어가기 위해 n/3을 해준다
    }
    

}

int main(){
    int n;
    cin>>n;
    
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n ; j++){
            printStar(i,j,n);
        }
        cout<<"\n";
    }
    return 0;
}