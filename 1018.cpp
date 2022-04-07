#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

string wb[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string bw[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string map[50];

int wb_map(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(map[x+i][y+j] != wb[i][j]){
                cnt+=1;
            }
        }
    }
    return cnt;
}

int bw_map(int x, int y){
    int cnt = 0;
    for(int i = 0; i < 8 ; i++){
        for(int j = 0 ; j < 8 ; j++){
            if(map[x+i][y+j] != bw[i][j]){
                cnt+=1;
            }
        }
    }
    return cnt;
}

int main(){
    int a,b;
    cin>>a>>b;
    int min_cnt = 999999;
    for(int i = 0; i < a ; i++){
        cin>>map[i];
    }
    for(int i = 0; i < a-7 ; i++){
        for(int j = 0; j < b-7 ; j++){
            int temp = min(wb_map(i,j),bw_map(i,j));
            if(temp < min_cnt){
                min_cnt = temp;
            }
        }
    }
    cout<<min_cnt;

    return 0;
}