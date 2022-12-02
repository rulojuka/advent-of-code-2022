#include<cstdio>
#include<queue>
#define MAXLINE 100
using namespace std;

int main(){
    int value;
    int currentSum = 0;
    char currentLine[MAXLINE];
    int response = 0;
    priority_queue<int> queue;
    do{
        if(fgets(currentLine,MAXLINE,stdin)==NULL){
            break;
        } else if(currentLine[0]=='\n'){
            queue.push(currentSum);
            currentSum=0;
        } else{
            sscanf(currentLine, "%d", &value);
            currentSum+=value;
        }
    } while (true);
    for(int i=0; i<3; i++){
        response += queue.top();
        queue.pop();
        if(i==0){
            printf("First challenge: %d\n",response);
        }
    }
    printf("Second challenge: %d\n",response);
    return 0;
}
