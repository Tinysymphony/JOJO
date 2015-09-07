#include <iostream>
#include <vector>

using namespace std;

int main() {
    int lengthA;
    int lengthB;
    long x;
    vector<long> listA, listB;
    scanf("%d", &lengthA);
    for(int i = 0; i < lengthA; i++){
        scanf("%ld", &x);
        listA.push_back(x);
    }
    scanf("%d", &lengthB);
    int total = lengthA + lengthB;
    for(int i = 0; i < lengthA; i++){
        scanf("%ld", &x);
        listB.push_back(x);
    }
    int index = (total - 1) / 2;
    int i = 0, j = 0, count = 0;
    while(i < lengthA && j < lengthB){
        if(listA[i] <= listB[j]){
            if(index == count){
                cout << listA[i] << endl;
                return 0;
            }
            i++;
        } else if(listA[i] > listB[j]) {
            if(index == count){
                cout << listB[j] << endl;
                return 0;
            }
            j++;
        }
        count++;
    }
    if(i==lengthA){
        cout << listB[j + index - count] << endl;
    } else if (j==lengthB){
        cout << listA[i + index - count] << endl;
    }
}