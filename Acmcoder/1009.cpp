
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Room{
public:
    int bean;
    int food;
    double rate;
    Room(int a = 0, int b = 0){
        bean = a;
        food = b;
        rate = ((double)a) / b;
    }
};

bool compare(Room a, Room b){
    return a.rate > b.rate;
}

int main(int argc, const char * argv[]) {

//    freopen("/Users/tiny/Desktop/input.txt", "r", stdin);
    int catFood, rooms;
    while(scanf("%d %d",&catFood, &rooms) != EOF){
        if(catFood == -1 && rooms == -1)
            return 0;
        vector<Room> list;
        for(int i = 0; i < rooms; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            list.push_back(Room(a, b));
        }
        sort(list.begin(), list.end(), compare);
        double result = 0;
        for(int i = 0; i < rooms; i++){
            if(list[i].food < catFood){
                result += list[i].bean;
                catFood -= list[i].food;
            } else {
                result += ((double)catFood) / list[i].food * list[i].bean;
                break;
            }
        }
        printf("%.3f\n", result);
    }
//    fclose(stdin);

    return 0;
}
