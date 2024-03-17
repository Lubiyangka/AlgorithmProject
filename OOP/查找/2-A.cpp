#include <iostream>
#include <algorithm>
using namespace std;
/*
    三分法求带权中位数 
*/
int N;
double l, r, mid, lm, rm;

struct City{
    double x;
    double p;
}city[15100];

bool cmp(City a, City b){
    return a.x <= b.x;
}

double dis(double loc){
    double sum = 0.0;
    for(int i = 0; i < N; i++){
        sum += abs(loc - city[i].x) * city[i].p;
    }
    return sum;
}

int main(){
    double min = 50001 * 1.0, max = 0.0;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>city[i].x>>city[i].p;
        if( city[i].x > max) max = city[i].x;
        if( city[i].x < min) min = city[i].x;
    }
    // sort(city, city + N, cmp);

    // l = city[0].x, r = city[N-1].x;
    l = min, r = max;
    while( r - l > 1e-8){
        mid = ( r - l ) / 3;
        lm = l + mid;
        rm = lm + mid;

        if(dis(lm) - dis(rm) <= 1e-8) r = rm;
        else l = lm;
    }
    printf("%.5lf", l);
}