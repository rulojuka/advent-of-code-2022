#include<cstdio>
#include<iostream>
using namespace std;

bool isInside(int a, int b, int c, int d){
    return (a>=c && b<=d) || (c>=a && d<=b);
}

bool doOverlap(int a, int b, int c, int d){
    return (a>=c && a<=d) || (b>=c && b<=d) || isInside(a,b,c,d);
}

int main(){
    int a,b,c,d;
    int resp1 = 0;
    int resp2 = 0;
    while ( scanf("%d%*c%d%*c%d%*c%d ",&a,&b,&c,&d) > 0){
        if(isInside(a,b,c,d)){
            resp1++;
        }
        if(doOverlap(a,b,c,d)){
            resp2++;
        }
    }
    cout << "First challenge: " << resp1 << endl;
    cout << "Second challenge: " << resp2 << endl;
    return 0;
}

