#include <iostream>
#include <queue>
#include <string>

using namespace std;

int map[100][100] = {0,};
int n,m, step = 0;
queue<pair<int,int>> primary;
queue<pair<int,int>> secondary;

int bfs();
int fillqueue();

int bfs(){
    step += 1;
    while(!primary.empty()){
        pair<int,int> top = primary.front();
        primary.pop();
        if(top.first == n-1 && top.second == m-1){
            return 0;
        }
        if(top.first > 0 && map[top.first-1][top.second] == 1){
            pair<int,int> up = make_pair(top.first-1,top.second);
            map[up.first][up.second] = 0;
            secondary.push(up);
        }
        if(top.first < n-1 && map[top.first+1][top.second] == 1){
            pair<int,int> down = make_pair(top.first+1,top.second);
            map[down.first][down.second] = 0;
            secondary.push(down);
        }
        if(top.second > 0 && map[top.first][top.second-1] == 1){
            pair<int, int> left = make_pair(top.first, top.second-1);
            map[left.first][left.second] = 0;
            secondary.push(left);
        }
        if(top.second < m-1 && map[top.first][top.second+1] == 1){
            pair<int, int> right = make_pair(top.first, top.second+1);
            map[right.first][right.second] = 0;
            secondary.push(right);
        }                
    }
    return fillqueue();
}
int fillqueue(){
    while(!secondary.empty()){
        primary.push(secondary.front());
        secondary.pop();
    }
    return bfs();
}


int main(){
    cin>>n>>m;
    for(int i = 0; i < n ; i++){
        string temp;
        cin>>temp;
        for(int j = 0; j < m ; j++){
            map[i][j] = temp[j]-'0';
        }
    }
    pair<int,int> z = make_pair(0,0);
    map[0][0] = 0;
    primary.push(z);
    bfs();
    cout<<step;
    return 0;
}