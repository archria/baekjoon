#include <iostream>
#include <queue>

using namespace std;

struct coor{
    int x;
    int y;
    int z;
};

int bfs();
int emptyQueue();

int map[102][102][102];
int n,m,h,tomatoNum = 0,step = 0;
queue<coor> primary;
queue<coor> secondary;

int bfs(){
    while(!primary.empty()){
        coor frnt = primary.front();
        primary.pop();
        tomatoNum--;
        int fx = frnt.x;
        int fy = frnt.y;
        int fz = frnt.z;
        if(map[fx-1][fy][fz] == 0){
            secondary.push({fx-1,fy,fz});
            map[fx-1][fy][fz] = 1;
        }
        if(map[fx+1][fy][fz] == 0){
            secondary.push({fx+1,fy,fz});
            map[fx+1][fy][fz] = 1;
        }
        if(map[fx][fy-1][fz] == 0){
            secondary.push({fx,fy-1,fz});
            map[fx][fy-1][fz] = 1;
        }
        if(map[fx][fy+1][fz] == 0){
            secondary.push({fx,fy+1,fz});
            map[fx][fy+1][fz] = 1;
        }
        if(map[fx][fy][fz-1] == 0){
            secondary.push({fx,fy,fz-1});
            map[fx][fy][fz-1] = 1;
        }
        if(map[fx][fy][fz+1] == 0){
            secondary.push({fx,fy,fz+1});
            map[fx][fy][fz+1] = 1;
        }
        
    }
    if(secondary.empty()){
        return 0;
    }
    else{
        return emptyQueue();
    }

}

int emptyQueue(){
    step++;
    while(!secondary.empty()){
        primary.push(secondary.front());
        secondary.pop();
    }
    return bfs();
}

int main(){
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102 ; j++){
            for(int k = 0; k < 102 ; k++){
                map[i][j][k] = -1;
            }
        }
    }
    cin>>m>>n>>h;
    for(int k = 1; k <= h ; k++){
        for(int j = 1; j <= n ; j++){
            for(int i = 1; i <= m ; i++){
                cin>>map[i][j][k];
                if(map[i][j][k] == 0)
                    tomatoNum++;
                else if(map[i][j][k] == 1){
                    primary.push({i,j,k});
                    tomatoNum++;
                }
            }
        }
    }
    bfs();
    //cout<<tomatoNum<<endl;
    if(tomatoNum != 0){
        cout<<"-1";
    }
    else{
        cout<<step;
    }

}