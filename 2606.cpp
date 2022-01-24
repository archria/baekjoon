#include <iostream>
#include <queue>

using namespace std;

int comLink[100];
int infectedComputer = 0;

bool Link[101][101] = {false};
bool visited[101] = {false};

void InfectedBFS(int com){
    queue<int> BFSInfect;
    BFSInfect.push(1);
    visited[1] = true;
    while(BFSInfect.empty() == false){
        int temp = BFSInfect.front();
        BFSInfect.pop();
        for(int i = 0; i <= com ; i++){
            if(Link[temp][i] == true && visited[i] == false){
                visited[i] = true;
                BFSInfect.push(i);
                infectedComputer += 1;
            }
        }
        
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int comNum;
    cin>>comNum;
    int linkNum;
    cin>>linkNum;
    for(int i = 0; i < linkNum ; i++){
        int from, to;
        cin>>from>>to;
        Link[from][to] = true;
        Link[to][from] = true;
    }
    // 무조건 1번 컴퓨터가 감염
    InfectedBFS(comNum);
    cout<<infectedComputer;


    return 0;
}