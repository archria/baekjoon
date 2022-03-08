#include <iostream>
#include <queue>

using namespace std;
int T;
int h,w,n;
int ans = 0;

void bfs(int board[50][50], int i, int j){
    queue<pair<int,int>> coor;
    pair<int,int> xy = make_pair(i,j);
    board[i][j] = 0;
    coor.push(xy);
    ans += 1;
    //cout<<"baechoo : "<<ans<<endl;
    while(!coor.empty()){
        pair<int,int> top = coor.front();
        //cout<<"coor : "<<top.first<<" "<<top.second<<endl;
        coor.pop();
        if(top.first > 0 && board[top.first-1][top.second] == 1){
            pair<int,int> up = make_pair(top.first-1, top.second);
            board[up.first][up.second] = 0;
            coor.push(up);
        }
        if(top.first < w-1 && board[top.first+1][top.second] == 1){
            pair<int,int> down = make_pair(top.first+1, top.second);
            board[down.first][down.second] = 0;
            coor.push(down);
        }
        if(top.second > 0 && board[top.first][top.second-1] == 1){
            pair<int,int> left = make_pair(top.first, top.second-1);
            board[left.first][left.second] = 0;
            coor.push(left);
        }
        if(top.second < h-1 && board[top.first][top.second+1] == 1){
            pair<int,int> right = make_pair(top.first, top.second+1);
            board[right.first][right.second] = 0;
            coor.push(right);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int i = 0; i < T ; i++){
        cin>>w>>h>>n;
        int board[50][50] = {0,};
        for(int j = 0 ; j < n ; j++){
            int a,b;
            cin>>a>>b;
            board[a][b] = 1;
        }
        ans = 0;
        for(int a = 0; a < h ; a++){
            for(int b = 0; b < w ; b++){
                if(board[b][a] == 1){
                    bfs(board,b,a);
                }
            }
        }
        cout<<ans<<"\n";
    }
    
    return 0;
}