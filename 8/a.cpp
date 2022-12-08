#include<iostream>
#include<string>

using namespace std;

#define INF 100
#define MAX 105
#define LINES 99
#define COLUMNS 99

//uncomment for example
//#define LINES 5
//#define COLUMNS 5

int v[MAX][MAX];

// N,S,E,W
int ii[]={-1,+1,0,0};
int jj[]={0,0,+1,-1};

int viewingDistanceIshForDirection(int i, int j, int height, int direction, int currentSteps){
    if(direction==0 && i==0) return INF;
    if(direction==1 && i>=LINES-1) return INF;
    if(direction==2 && j>=COLUMNS-1) return INF;
    if(direction==3 && j==0) return INF;
    if(height<=v[i+ii[direction]][j+jj[direction]]) return currentSteps+1;
    return viewingDistanceIshForDirection(i+ii[direction],j+jj[direction],height,direction,currentSteps+1);
}

int distanceToEndInDirection(int i, int j, int direction){
    if(direction == 0) return i;
    if(direction == 1) return LINES-i-1;
    if(direction == 2) return COLUMNS-j-1;
    return j;
}

int seesEnd(int i,int j){
    int viewingDistance;
    int distanceToEnd;
    for(int k=0; k<4; k++){
        viewingDistance = viewingDistanceIshForDirection(i,j,v[i][j],k,0);
        distanceToEnd = distanceToEndInDirection(i,j,k);
        if(viewingDistance>distanceToEnd) return 1;
    }
    return 0;
}

int viewingDistance(int i, int j, int direction){
    int viewingDistance = viewingDistanceIshForDirection(i,j,v[i][j],direction,0);
    int distanceToEnd = distanceToEndInDirection(i,j,direction);
    return min(viewingDistance,distanceToEnd);
}

int main(){
    char current;
    for(int i=0;i<LINES;i++){
        for(int j=0; j<COLUMNS; j++){
            scanf("%c ",&current);
            v[i][j]=current-'0';
        }
    }

    // Problem 1
    int responseOne=0;
    for(int i=0;i<LINES;i++){
        for(int j=0; j<COLUMNS; j++){
            if(seesEnd(i,j)==1) responseOne++;
        }
    }
    printf("%d\n",responseOne);

    // Problem 2
    int best=0;
    long product;
    for(int i=1;i<LINES-1;i++){
        for(int j=1; j<COLUMNS-1; j++){
            product = 1;
            for(int k=0;k<4;k++){
                product *= viewingDistance(i,j,k);
            }
            if(product>best) best = product;
        }
    }
    printf("%d\n",best);

    return 0;
}