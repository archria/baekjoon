#include <iostream>

using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i = 0; i < T; i++){
        int x1,y1,r1,x2,y2,r2;
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        int x = abs(x2-x1);
        int y = abs(y2-y1);
        int len = x*x + y*y;
        int rP = abs(r1+r2);
        int rM = abs(r1-r2);
        if(len < rP*rP && len > rM*rM){
            cout<<"2\n";
        }
        else if(len == rP*rP){
            cout<<"1\n";
        }
        else if(len == rM*rM && len != 0){
            cout<<"1\n";
        }
        else if(len < rM*rM){
            cout<<"0\n";
        }
        else if(len > rP*rP){
            cout<<"0\n";
        }
        else if(len == 0 && r1 == r2){
            cout<<"-1\n";
        }
        else
            cout<<"0\n";
        
    }
    return 0;


}