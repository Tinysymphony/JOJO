#include <iostream>
#include <queue>
using namespace std;

class People {
public:
    int waitTime = 0;
    int handleTime = 0;
    int time = 0;
    bool isHandled(){ return (this->waitTime - this->time) < 540; }
};

int findSmallest(queue<People*> lines[], int size) {
    int min = 10000000;
    int index = -1;
    for(int i = 0; i < size; i++) {
        if (lines[i].front() && lines[i].front()->handleTime < min) {
            min = lines[i].front()->handleTime;
            index = i;
        }
    }
    return index;
}

void decTime(queue<People*> lines[], int size, int num) {
    for(int i = 0; i < size; i++){
        if(lines[i].front()){
            lines[i].front()->handleTime -= num;
        }
    }
}

int main() {
    int win, cap, count, query;
    cin >> win >> cap >> count >> query;

    int queryList[query];
    People* clients[count];
    queue<People*> lines[win];

    for(int i = 0; i < count; i++){
        clients[i] = (People*)malloc(sizeof(People));
        cin >> clients[i]->time;
        clients[i]->handleTime = clients[i]->time;
        if(i < cap * win){
            lines[i % win].push(clients[i]);
        }
    }

    for(int i = 0; i < query; i++) {
        cin >> queryList[i];
    }

    int time = 0;
    int target = count > win * cap ? win * cap : count;
    while(true) {
        int index = findSmallest(lines, win);
        if(index == -1)
            break;
        int handle = lines[index].front()->handleTime;
        time += handle;
        decTime(lines, win, handle);
        lines[index].front()->waitTime = time;
        lines[index].pop();
        if(target != count) {
            lines[index].push(clients[target]);
            target++;
        }
    }

    for(int i = 0; i < query; i++){
        int index = queryList[i] - 1;
        if(!clients[index]->isHandled()){
            cout << "Sorry" << endl;
            continue;
        }
        int output  = clients[index]->waitTime;
        int hour = output / 60 + 8;
        int min = output % 60;
        printf("%02d:%02d\n", hour, min);
    }
}
