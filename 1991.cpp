#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int map[26][2];

void preorder(int pos){
    cout<<char(pos + 'A');
    if(map[pos][0] != 9999){
        preorder(map[pos][0]);
    }
    if(map[pos][1] != 9999){
        preorder(map[pos][1]);
    }
}

void inorder(int pos){
    if(map[pos][0] != 9999){
        inorder(map[pos][0]);
    }
    cout<<char(pos+'A');
    if(map[pos][1] != 9999){
        inorder(map[pos][1]);
    }
}

void postorder(int pos){
    if(map[pos][0] != 9999){
        postorder(map[pos][0]);
    }
    if(map[pos][1] != 9999){
        postorder(map[pos][1]);
    }
    cout<<char(pos+'A');

}


int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n ; i++){
        char a,b,c;
        cin>>a>>b>>c;
        if(b != '.'){
            map[a-'A'][0] = b-'A';
        }
        else{
            map[a-'A'][0] = 9999;
        }
        if(c != '.'){
            map[a-'A'][1] = c-'A';
        }
        else{
            map[a-'A'][1] = 9999;
        }
    }
    preorder(0);
    cout<<"\n";
    inorder(0);
    cout<<"\n";
    postorder(0);



    return 0;
}