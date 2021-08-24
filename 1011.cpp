#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T;
    long long x,y;
    cin>>T;
    int distance = 0;
    long long gone = 0;
    int time;
    for(int i = 0; i < T; i++){
        cin>>x;
        cin>>y;
        distance = y-x;
        if(distance == 2){
            std::cout<<"2"<<"\n";
        }
        else if(distance == 3){
            std::cout<<"3"<<"\n";
        }
        else{ // if distance >= 4
            //gone = 4; // 1+2+1
            
            int step = 2;
            step = distance;
            step = sqrt(step);
            //cout<<"max step : "<<step << endl;
            // while(true){ (O (y-x))
            //     if(gone + 2*step +1 > distance){ // gone + step-1 (last step) + step(max speed)
            //         break; // we can't go.
            //     }
            //     else{
            //         gone = gone + 2*step +1; // ex) 1+2+1  + 2+3 = 1+2+3+2+1 < distance
            //         step++; // step = 3.
            //     }
            // }
            gone = pow(step,2);
            //cout<<"gone : "<<gone<<endl;
            time = 2*(step-1) + 1;
            // step = max distance at one step at this distance
             // gone = gone distance at pyramid distance (ex. 1+2+3+2+1 = 9)
            distance = distance - gone; // left distance minus gone;
            //cout<<"time : "<<time<<endl;
            //cout<<"left distance : "<<distance<<endl;
            if(distance != 0){
                if(step >= distance)
                    cout<<time + 1 <<"\n";
                else if(step < distance)
                    cout<<time + 2 <<"\n";
            }
            else // no more distance
                cout<<time<<"\n";
            
        }

    }
    return 0;
}