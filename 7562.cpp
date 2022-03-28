#include <iostream>
#include <queue>
#define endl "\n"
using namespace std;

int map[300][300];
int n,M,step = 1;
int cx,cy,tx,ty;

queue<pair<int,int>> chess;
queue<pair<int,int>> secondary;

int fillQueue();

int BFS(){
    while(!chess.empty()){
        int x = chess.front().first;
        int y = chess.front().second;
        chess.pop();
        //cout<<"step : "<<step<<endl;
        //cout<<"x : "<<x<<" y : "<<y<<endl;
        if(x == tx && y == ty) return 0;
        if(x-2 >= 0 && y-1 >= 0 && map[x-2][y-1] == 0){
            map[x-2][y-1] = step;
            secondary.push({x-2,y-1});
        }
        if(x-1 >= 0 && y-2 >= 0 && map[x-1][y-2] == 0){
            map[x-1][y-2] = step;
            secondary.push({x-1,y-2});
        }
        if(x-2 >= 0 && y+1 < M && map[x-2][y+1] == 0){
            map[x-2][y+1] = step;
            secondary.push({x-2,y+1});
        }
        if(x-1 >= 0 && y+2 < M && map[x-1][y+2] == 0){
            map[x-1][y+2] = step;
            secondary.push({x-1,y+2});
        }
        if(x+1 < M && y-2 >= 0 && map[x+1][y-2] == 0){
            map[x+1][y-2] = step;
            secondary.push({x+1,y-2});
        }
        if(x+2 < M && y-1 >= 0 && map[x+2][y-1] == 0){
            map[x+2][y-1] = step;
            secondary.push({x+2,y-1});
        }
        if(x+2 < M && y+1 < M && map[x+2][y+1] == 0){
            map[x+2][y+1] = step;
            secondary.push({x+2,y+1});
        }
        if(x+1 < M && y+2 < M && map[x+1][y+2] == 0){
            map[x+1][y+2] = step;
            secondary.push({x+1,y+2});
        }
    }
    if(!secondary.empty()){
        return fillQueue();
    }
    else{
        return 0;
    }
}

int fillQueue(){
    //cout<<"fill step : "<<step<<endl;
    step += 1;
    while(!secondary.empty()){
        chess.push(secondary.front());
        secondary.pop();
    }
    return BFS();
}

int main(){
    cin>>n;
    for(int i = 0; i < n ; i++){
        cin>>M;
        for(int j = 0; j < M ; j++){
            for(int k = 0; k < M ; k++){
                map[j][k] = 0;
            }
        }
        while(!chess.empty()){
            chess.pop();
        }
        while(!secondary.empty()){
            secondary.pop();
        }
        step = 1;
        cin>>cx>>cy;
        cin>>tx>>ty;
        map[cx][cy] = 1;
        chess.push({cx,cy});
        if(cx == tx && cy == ty){
            cout<<"0";
        }
        else{
            BFS();
            cout<<map[tx][ty];
        }
        cout<<"\n";
    }

    return 0;
}