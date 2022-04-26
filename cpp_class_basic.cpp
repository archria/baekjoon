#include <iostream>

using namespace std;

class myFuncClass{
protected:
    int fuel = 0;
    bool power = false;

public:
    myFuncClass(){
        int fuel = 100;
        bool power = true;
    }
    myFuncClass(int n){
        int fuel = n;
        bool power = true;
    }
    void go(){
        this->fuel--;
    }
    void gas_station(int n){
        this->fuel += n;
    }
    void fuel_check(){
        cout<<"fuel : "<<this->fuel<<endl;
    }
};

class myChildClass : public myFuncClass{
public:
    void go(){
        this->fuel -= 2;
    }
};

int main(){
    myChildClass suv = myChildClass();
    myFuncClass car = myFuncClass();
    
    car.fuel_check();

    suv.gas_station(6);
    suv.fuel_check();
    suv.go();
    suv.fuel_check();

}