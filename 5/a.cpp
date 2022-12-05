/**
* In order for this solution to work you have
* to strip the first lines from the input.
*
* In the end, your input must start with the first:
* "move n from x to y"
*/

#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<char> stacks[2][10];

void pushToVector(int i, string letters){
    for(auto letter : letters)
    {
    	stacks[0][i].push_back(letter);
        stacks[1][i].push_back(letter);
    }
}

void move1(int n, int x, int y){
    for(int i=0; i<n; i++){
        stacks[0][y].push_back(stacks[0][x].back());
        stacks[0][x].pop_back();
    }
}

void move2(int n, int x, int y){
    vector<int> tmp;
    tmp.clear();
    for(int i=0; i<n; i++){
        tmp.push_back(stacks[1][x].back());
        stacks[1][x].pop_back();
    }
    for(int i=0; i<n; i++){
        stacks[1][y].push_back(tmp.back());
        tmp.pop_back();
    }
}

int main(){
    int n;
    int a,b,c;

    //Example
    /*
    pushToVector(0,"ZN");
    pushToVector(1,"MCD");
    pushToVector(2,"P");
    n=3;
    */
    
    pushToVector(0,"GDVZJSB");
    pushToVector(1,"ZSMGVP");
    pushToVector(2,"CLBSWTQF");
    pushToVector(3,"HJGWMRVQ");
    pushToVector(4,"CLSNFMD");
    pushToVector(5,"RGCD");
    pushToVector(6,"HGTRJDSQ");
    pushToVector(7,"PFV");
    pushToVector(8,"DRSTJ");
    n=9;

    while(scanf("%*s %d %*s %d %*s %d ",&a,&b,&c)>0){
        move1(a,b-1,c-1);
        move2(a,b-1,c-1);
    }

    for(int j=0;j<2;j++){
        for(int i=0; i<n; i++){
            printf("%c",stacks[j][i].back());
        }
        printf("\n");
    }

    return 0;
}

