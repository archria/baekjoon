#include <iostream>

using namespace std;
int ans = 0;

bool chessBoard[15][15] = {false};
// chessBoard[x][y] = true or false;

bool isPossible(int x, int loop, int n){
    // 체스판 x,y에 Queen을 놓으려고 한다. 이 때 주의해야 할 점은?
    for(int i = 0; i < loop ; i++){
        if(chessBoard[x][i] == true){
            //cout<<i<<" "<<loop<<" can't place\n";
            return false;
        }
    }
    int xm = x, ym = loop;
    while(true){
        xm--;
        ym--;
        if(xm < 0 || ym < 0)
            break;
        else{
            if(chessBoard[xm][ym] == true){
                return false;
            }
        }
    }
    xm = x, ym = loop;
    while(true){
        xm++; ym--;
        if(xm == n || ym < 0) break;
        else{
            if(chessBoard[xm][ym] == true){
                return false;
            }
        }
    }
    return true;
}

void QueenLoop(int n, int loop){
    // x . loop에 위치시킨다
    int x;
    if(loop == n){
        ans++;
    }
    else {
        for(int i = 0; i < n ; i++){
            if(isPossible(i,loop,n) == true){
                chessBoard[i][loop] = true;
                //cout<<i<<" "<<loop<<endl;
                QueenLoop(n,loop+1);
                chessBoard[i][loop] = false;
            }
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    QueenLoop(n,0);
    cout<<ans;
    return 0;
}