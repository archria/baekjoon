#include <iostream>
#include <algorithm>
using namespace std;

struct personInfo{
    int age;
    string name;
};

bool ageSort(personInfo left, personInfo right){
    if(left.age < right.age)
        return true;
    return false;
}

int main(){
    int N;
    cin>>N;
    personInfo *people = new personInfo[N];
    for(int i = 0; i < N ; i++){
        cin>>people[i].age>>people[i].name;
    }
    stable_sort(people, people+N, ageSort);
    for(int i = 0; i < N ; i++){
        cout<<people[i].age<<" "<<people[i].name<<"\n";
    }
    return 0;
}