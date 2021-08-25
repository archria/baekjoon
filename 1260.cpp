#include <iostream>
#include <queue>

void DFS(bool arr[1001][1001], int start);
void BFS(bool arr[1001][1001], int start);

using namespace std;

queue<int> waitlist;
int N,M,V;
bool arr[1001][1001] = {false};
bool visited[1001] = {false};
int main(){

    cin>>N; //number of point
    cin>>M; // number of line
    cin>>V; // starting point
    int x,y;
    for(int i = 0; i < M; i++){
        cin>>x;
        cin>>y;
        arr[x][y] = true;
        arr[y][x] = true;
    } // draw map
    //first node visit
    visited[V] = true;
    cout<<V<<" ";
    //from first
    DFS(arr,V);
    cout<<endl;

    //initialize visited array
    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
    // first node visit
    visited[V] = true;

    //from first 
    BFS(arr,V);



}

void DFS(bool arr[1001][1001], int start){
    for(int i = 1; i <= N; i++){
        if(arr[start][i] == true && visited[i] == false){ // never visited point and can go
            cout<<i<<" ";
            visited[i] = true;
            DFS(arr, i);
        }
    }
}

void BFS(bool arr[1001][1001], int start){
    waitlist.push(start);
    while(waitlist.empty() == false){
        cout<<waitlist.front()<<" ";
        for(int i = 0; i <= N ; i++){
            if(arr[waitlist.front()][i] == true && visited[i] == false){
                waitlist.push(i);
                visited[i] = true;
            }
        }
        waitlist.pop();
    }
}