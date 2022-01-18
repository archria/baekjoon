#include <iostream>
#include <queue>

using namespace std;

int sudokuBoard[9][9] ={0};
bool isUsed[10] = {false};
int howManyZero = 0;
struct coor{
    int x;
    int y;
};
queue<coor> zeroCoordinate;
queue<coor> temp;

int answer(){
    int ans;

    return ans;
}

void solveSudoku(int i, int j){
        
}

int main(){
    for(int i = 0; i < 9 ; i++){
        for(int j = 0; j < 9 ; j++){
            int a;
            if(a == 0){
                howManyZero += 1; // 0 갯수 측정
            }
        }
    }//스도쿠 판 입력

    while(howManyZero > 0){
        for(int i = 0; i < 9 ; i++){
            for(int j = 0; j < 9 ; j++){
                if(sudokuBoard[i][j] == 0){
                    solveSudoku(i,j);
                }
            }
        }

    }
    
        
    return 0;
}