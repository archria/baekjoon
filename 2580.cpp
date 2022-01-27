#include <iostream>
#include <queue>

using namespace std;

int sudokuBoard[9][9] ={0};
bool isUsed[10] = {false};
int howManyZero = 0;

int main(){
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9 ; j++){
            int a;
            if(a == 0){
                howManyZero += 1; // 0 갯수 측정
            }
        }
    }//스도쿠 판 입력

    
    
        
    return 0;
}