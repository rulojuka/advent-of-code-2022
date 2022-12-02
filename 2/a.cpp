#include<cstdio>
#include<map>
using namespace std;

int main(){
    char playerA, playerB;
    map< pair<char,char> , int > count;
    map< pair<char,char> , int > points1;
    map< pair<char,char> , int > points2;
    pair<char,char> currentPair;
    int currentValue;
    int totalSum1 = 0;
    int totalSum2 = 0;

    // points1: X=rock Y=paper Z=scissors
    // points2: X=lose Y=draw Z=win
    currentPair = make_pair('A','X');
    points1[currentPair] = 4; // 1 + 3
    points2[currentPair] = 3; // 3 + 0
    currentPair = make_pair('A','Y');
    points1[currentPair] = 8; // 2 + 6
    points2[currentPair] = 4; // 1 + 3
    currentPair = make_pair('A','Z');
    points1[currentPair] = 3; // 3 + 0
    points2[currentPair] = 8; // 2 + 6
    currentPair = make_pair('B','X');
    points1[currentPair] = 1; // 1 + 0
    points2[currentPair] = 1; // 1 + 0
    currentPair = make_pair('B','Y');
    points1[currentPair] = 5; // 2 + 3
    points2[currentPair] = 5; // 2 + 3
    currentPair = make_pair('B','Z');
    points1[currentPair] = 9; // 3 + 6
    points2[currentPair] = 9; // 3 + 6
    currentPair = make_pair('C','X');
    points1[currentPair] = 7; // 1 + 6
    points2[currentPair] = 2; // 2 + 0
    currentPair = make_pair('C','Y');
    points1[currentPair] = 2; // 2 + 0
    points2[currentPair] = 6; // 3 + 3
    currentPair = make_pair('C','Z');
    points1[currentPair] = 6; // 3 + 3
    points2[currentPair] = 7; // 1 + 6


    while(scanf("%c %c ",&playerA,&playerB)==2){
        currentPair = make_pair(playerA,playerB);
        count[currentPair]++;
    }
    //printf("Final responses:\n");
    for (map< pair<char,char> , int >::iterator it=count.begin(); it!=count.end(); ++it){
        currentPair = it->first;
        currentValue = it->second;
        //printf("%c %c: %d\n",currentPair.first, currentPair.second,currentValue);
        totalSum1 += points1[currentPair]*currentValue;
        totalSum2 += points2[currentPair]*currentValue;
        //printf("Total sum: %d\n",totalSum);
    }
    printf("points1: %d\npoints2: %d\n",totalSum1,totalSum2);
    return 0;
}
