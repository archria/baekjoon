#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int map[25][25] = { 0, };

struct coor{
    int i;
    int j;
};

vector<int> ans;

int checkAPT(int i, int j){
    int apt;
    queue<coor> tmp;
    coor origin;
    origin.i = i;
    origin.j = j;
    tmp.push(origin);
    while(tmp.empty() == false){
        coor nowcoor;
        nowcoor = tmp.front();
        tmp.pop();
        apt += 1;
        coor left,right,up,down;
        // 위 아래 왼쪽 오른쪽 검사해서 유효한경우 큐에 추가해줌        
        
    }
    
    return apt;
}

int main(){
    int N;
    cin>>N;
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < N ; j++){
            cin>>map[i][j];
        }
    }
    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            if(map[i][j] == 1){
                ans.push_back(checkAPT(i,j));
            }
        }
    }
    sort(ans.begin(), ans.end());
    // 맵 입력받음 아파트 = 1
    // 아파트 규모 체크한 이후에 아파트를 0으로 해주면 상관없지 않나?
    // 굳이 색칠하는게 아닌, 그저 규모 체크 -> vector에 추가
    // 마지막에 sort(vec.begin() ,vec.end()) 해주면 끝나는게 아닌가.
    cout<<ans.size()<<"\n";
    for(int i = 0; i < ans.size() ; i++){
        cout<<ans[i]<<"\n";
    }

    
    
    return 0;
}