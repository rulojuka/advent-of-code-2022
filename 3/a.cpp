#include<iostream>
#include<set>
using namespace std;

set<char> groupSets[3];
string line;

char getRepeated(){
    set<char> letterSet;
    int size = line.size();
    int halfSize = size>>1;
    for (int i=0; i<halfSize; i++){
            letterSet.insert(line[i]);
    }
    for (int i=halfSize; i<size; i++){
        if(letterSet.count(line[i])>0){
            return line[i];
        }
    }
    return '-';
}

int getPriority(char letter){
    if(letter>='a' && letter <='z') return letter - 'a' + 1;
    return letter - 'A' + 27;
}

void addLineToSet(int setNumber){
    for (auto character : line) {
        groupSets[setNumber].insert(character);
    }
}

char getGroupBadge(){
    for(char letter='A'; letter<='z'; letter++){
        if(groupSets[0].count(letter)==1 &&
           groupSets[1].count(letter)==1 &&
           groupSets[2].count(letter)==1){
            return letter;
           }
    }
    return '-';
}

int main(){
    int totalSum = 0;
    int totalGroupSum = 0;
    int count = 0;
    while (getline(cin, line)){
        totalSum += getPriority(getRepeated());
        
        addLineToSet(count%3);
        if(count%3==2){
            char groupBadge = getGroupBadge();
            totalGroupSum += getPriority(groupBadge);
            for(int i=0; i<3; i++) groupSets[i].clear();
        }
        count ++;
    }
    cout << "First challenge: " << totalSum << endl;
    cout << "Second challenge: " << totalGroupSum << endl;
    return 0;
}

