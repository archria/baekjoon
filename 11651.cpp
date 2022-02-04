#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct xy{
    int x;
    int y;
};

bool sorting(xy left, xy right){
    if(left.y < right.y){
        return true;
    }
    else if(left.y < right.y){
        return false;
    }
    else if(left.y == right.y){
        if(left.x < right.x){
            return true;
        }
        else if(left.x > right.x){
            return false;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<xy> coor;
    for(int i = 0; i < n ; i++){
        xy temp;
        cin>>temp.x>>temp.y;
        coor.push_back(temp);
    }
    sort(coor.begin(), coor.end(), sorting);
    for(int i = 0; i < n ; i++){
        cout<<coor[i].x<<" "<<coor[i].y<<"\n";
    }    

}