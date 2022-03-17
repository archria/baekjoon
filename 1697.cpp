#include <iostream>
#include <queue>

using namespace std;

queue<int> primary;
queue<int> secondary;

int step = 0;
int map[100001] = {0,};
    int n,k;
int bfs();
int queueRefill();

int bfs(){
    while(!primary.empty()){
        int frnt = primary.front();
        if(frnt == k){
            return 0;
        }
        primary.pop();
        if(frnt-1 >= 0 && map[frnt-1] == 0){
            map[frnt-1] = step;
            secondary.push(frnt-1);
        }
        if(frnt+1 <= 100000 && map[frnt+1] == 0){
            map[frnt+1] = step;
            secondary.push(frnt+1);
        }
        if(frnt*2 <= 100000 && map[frnt*2] == 0){
            map[frnt*2] = step;
            secondary.push(frnt*2);
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
    step++;
    while(!secondary.empty()){
        primary.push(secondary.front());
        secondary.pop();
    }
    return bfs();
}

int main(){

    cin>>n>>k;
    map[n] == 99999;    
    if(n == k){
        cout<<"0";
        return 0;
    }
    primary.push(n);
    bfs();
    cout<<step;

    
}