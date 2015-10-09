
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct Point{
    double x;
    double y;
}p[100000];

int tmp[100000];

double compareX(Point x, Point y){
    return x.x < y.x;
}

double compareY(int x, int y){
    return p[x].y < p[y].y;
}

double calDistance(Point x, Point y){
    return (double)sqrt(pow(x.x - y.x, 2) + pow(x.y - y.y, 2));
}

double min(double a, double b){
    return (a <= b) ? a : b;
}

double min3(double a, double b, double c){
    return min(a, min(b, c));
}

double minDistanceY(double minDist, int arr[], int start, int end){
    double result = minDist;
    for(int i = start; i <= end; i++){
        for(int j = i + 1; j <= end; j++){
            if(p[arr[j]].y - p[arr[i]].y >= minDist) break;
            result = min(result, calDistance(p[arr[i]], p[arr[j]]));
        }
    }
    return result;
}

double minDistanceX(int start, int end){
    int length = end - start;
    if(end == start)
        return 0;
    if(length == 1)
        return calDistance(p[start], p[end]);
    if(length == 2)
        return min3(calDistance(p[start], p[start + 1]), calDistance(p[start + 1], p[end]), calDistance(p[start], p[end]));
    int leftEnd = (start + end) / 2;
    int rightStart = leftEnd + 1;
    double minLeft = minDistanceX(start, leftEnd);
    double minRight = minDistanceX(rightStart, end);
    double minDist = min(minLeft, minRight);
    double center = (p[leftEnd].x + p[rightStart].x) / 2;

    int centerStart = -1, centerEnd = -1;
    for(int i = start; i <= leftEnd; i++){
        if(center - p[i].x < minDist){
            centerStart = i;
            break;
        }
    }
    for(int i = end; i >= rightStart; i--){
        if(p[i].x  - center < minDist){
            centerEnd = i;
            break;
        }
    }
    if(centerStart == -1 || centerEnd == -1){
        return minDist;
    }

    int centerLength = centerEnd - centerStart + 1;

    for(int i = 0; i < centerLength; i++){
        tmp[i] = centerStart + i;
    }

    sort(tmp, tmp + centerLength, compareY);

    return minDistanceY(minDist, tmp, 0, centerLength - 1);
}

int main(int argc, const char * argv[]) {
    int times;
    while(scanf("%d", &times) != EOF){
        if(times == 0)
            return 0;
        for(int i = 0; i < times; i++){
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        sort(p, p + times, compareX);
        printf("%.2f\n", minDistanceX(0, times - 1) / 2);
    }
    return 0;
}
