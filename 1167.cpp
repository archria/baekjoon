#include <iostream>
#include <vector>

using namespace std;

struct line{
    int goal;
    int distance;
};

vector<line> nodes[100001];
bool visited[100001] = {false};
int dist = 0;
int longest = 0;
int farPoint = 0;
void DFSLine(int startingPoint, int dist){
    for(int i = 0 ; i < nodes[startingPoint].size() ; i++){
        if( visited [ nodes[startingPoint][i].goal ] == false ){
            visited[ nodes[startingPoint][i].goal ] = true;
            //cout<<"route : "<<nodes[startingPoint][i].goal<<endl;
            farPoint = nodes[startingPoint][i].goal;
            DFSLine( nodes[startingPoint][i].goal , dist+ nodes[startingPoint][i].distance);
            visited[ nodes[startingPoint][i].goal ] = false;
        }
    }
    if(longest < dist){
        longest = dist;
    }
}

int main(){
    int v;
    cin>>v;
    for(int i = 0; i < v ; i++){
        int node;
        cin>>node;
        while(true){
            int a,b;
            cin>>a;
            if(a == -1) break;
            else cin>>b;
            line temp;
            temp.goal = a;
            temp.distance = b;
            nodes[node].push_back(temp);
        }
    }
    visited[1] = true;
    DFSLine(1,0);
    //cout<<"farpoint : "<<farPoint<<endl;  
    visited[1] = false;
    for(int i = 0; i <= v ; i++){
        visited[i] = false;
    }
    visited[farPoint] = true;
    DFSLine(farPoint,0);

    cout<<longest;

    return 0;
}