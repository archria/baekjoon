#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int dist[20001];
vector<pair<int,int>> vertex[20001];


int main(){
    int V,E,K;
    cin>>V>>E>>K;
    for(int i = 0; i < E; i++){
        int a,b,c;
        cin>>a>>b>>c;
        vertex[a].push_back({b,c});
    }
    for(int i = 1; i <= V; i++){
        dist[i] = 99999999;
    }

    priority_queue<pair<int,int>> pq;
    pq.push({0,K});

        
    
    return 0;
}