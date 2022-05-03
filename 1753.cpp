#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int dist[20001];
vector<pair<int,int>> vertex[20001];


int main(){
    int V,E,K;
    cin>>V>>E>>K; // 정점 갯수, 간선 갯수, 시작지점
    for(int i = 0; i < E; i++){
        int a,b,c;
        cin>>a>>b>>c; // a -> b로 가는 간선이 가중치 c
        vertex[a].push_back({b,c}); // 목적지 b, 가중치 c
    }
    for(int i = 1; i <= V; i++){
        dist[i] = 99999999; // 처음에 0에서 출발하는 거리를 모두 큰 값으로 설정해줌.
    }

    priority_queue<pair<int,int>> pq;
    pq.push({0,K});
    // pq를 통해 간선이 있는 곳만 알아낼 수 있고, 순서대로 1~N까지의 노드를 순차적으로 Daijkstra 를 적용할 수 있다.
    // 간선이 없으면 pq에 입력되지 않음 == 있는곳만 알아냄
    dist[K] = 0;
    while(!pq.empty()){
        int dest = pq.top().first;
        int current = pq.top().second;
    }

    
            
    
    return 0;
}