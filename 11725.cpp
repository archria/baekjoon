#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> nodes[100001];
queue<int> bfsQueue;
int tops[100001];


int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n-1 ; i++){
        int left,right;
        cin>>left>>right;
        nodes[left].push_back(right);
        nodes[right].push_back(left);
    }
    bfsQueue.push(1);
    while(bfsQueue.empty() == false){
        int nowNode = bfsQueue.front();
        bfsQueue.pop();
        for(int i = 0; i < nodes[nowNode].size() ; i++){
            if(tops[ nowNode ] == nodes[nowNode][i] ) continue; // 현재 노드에서 뻗어나가는 간선중 부모 노드를 발견한다면? skip 
            // 그렇지 않다면 bfs에 추가
            tops[ nodes[nowNode][i] ] = nowNode;
            bfsQueue.push(nodes[nowNode][i]);
        }       
    }
    for(int i = 2 ; i <= n ; i++){
        cout<<tops[i]<<"\n";
    }

    return 0;
}