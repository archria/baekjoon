#include <iostream>
#include <queue>

using namespace std;

int map[1002][1002] = {-1,};
int ans = 1;
int tomatonum =0;
int loopConut = 0; 
queue<pair<int,int>> tomato;
queue<pair<int,int>> secondary;

int bfs();
int queueRefill();

int bfs(){
    while(!tomato.empty()){
        pair<int,int> frnt = tomato.front();
        tomato.pop();
        tomatonum--;
        //cout<<frnt.first<< " "<<frnt.second<<endl;
        if(map[frnt.first-1][frnt.second] == 0){
            map[frnt.first-1][frnt.second] = map[frnt.first][frnt.second] + 1;
            secondary.push({frnt.first-1,frnt.second});
            ans = map[frnt.first-1][frnt.second];
        }
        if(map[frnt.first+1][frnt.second] == 0){
            map[frnt.first+1][frnt.second] = map[frnt.first][frnt.second] + 1;
            secondary.push({frnt.first+1,frnt.second});
            ans = map[frnt.first+1][frnt.second];
        }
        if(map[frnt.first][frnt.second-1] == 0){
            map[frnt.first][frnt.second-1] = map[frnt.first][frnt.second] + 1;
            secondary.push({frnt.first,frnt.second-1});
            ans = map[frnt.first][frnt.second-1];
        }
        if(map[frnt.first][frnt.second+1] == 0){
            map[frnt.first][frnt.second+1] = map[frnt.first][frnt.second] + 1;
            secondary.push({frnt.first,frnt.second+1});
            ans = map[frnt.first][frnt.second+1];
        }
    }
    if(secondary.empty()){
        return 0;
    }
    else{
        return queueRefill();
    }
}

int queueRefill(){
    while(!secondary.empty()){
        tomato.push(secondary.front());
        secondary.pop();
    }
    return bfs();
}

int main(){
    int m,n;
    for(int i = 0; i < 1002 ; i++){
        for(int j = 0; j < 1002 ; j++){
            map[i][j] = -1;
        }
    }
    cin>>m>>n; // m = 가로 n = 세로
    for(int i = 1; i <= n ; i++){
        for(int j = 1; j <= m ; j++){
            cin>>map[i][j];
            if(map[i][j] == 1){
                tomato.push({i,j});
                tomatonum++;
            }
            else if(map[i][j] == 0){
                tomatonum++;
            }
        }
    }
    bfs();

    if(tomatonum == 0){
        cout<<ans-1;
    }
    else
        cout<<"-1";

    return 0;
}