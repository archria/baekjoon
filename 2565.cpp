#include <iostream>
#include <algorithm>

using namespace std;

struct Tower{
    int A;
    int B;
};

bool ATowerSort(Tower front, Tower back){
    if(front.A < back.A)
        return true;
    return false;
}

int main(){
    int N;
    cin>>N;
    Tower *towers = new Tower[N+1];
    for(int i = 0; i < N ; i++){
        cin>>towers[i].A>>towers[i].B;
    }
    
    sort(towers, towers+N, ATowerSort); // A 타워 기준으로 오름차순 정렬

    int *length = new int[N+1];
    for(int k = 0 ; k < N ; k++){
        length[k] = 1;
        for(int i = 0; i < k ; i++){
            if(towers[i].B < towers[k].B){
                length[k] = max(length[k],length[i]+1);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N ; i++){
        if(length[i] > ans)
            ans = length[i];
    }  
    
    cout<<N-ans;

    return 0;
}