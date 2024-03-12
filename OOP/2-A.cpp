#include <iostream>
#include <algorithm>
using namespace std;

int N;
struct City{
    double x;
    double p;
}city[15000];

bool cmp(City a, City b){
    return a.x <= b.x;
}

int main(){
    int sum = 0;
    cin>>N;
    for(int i = 0; i < N; i++){
        cin>>city[i].x>>city[i].p;
        sum += city[i].p;
    }
    sort(city, city + N, cmp);

    if(sum % 2 != 0){
        int s = 0;
        for(int i = 0; i < N; i++){
            s += city[i].p;
            if(s >= (sum + 1) / 2) {
                printf("%.5lf", city[i].x);
                break;
            }
        }
    }else{
        int s = 0;
        for(int i = 0; i < N; i++){
            s += city[i].p;
            if(s >= sum / 2) {
                if(s >= sum /2 +1){
                    printf("%.5lf", city[i].x);
                    break;
                }else{
                    printf("%.5lf", (city[i].x + city[i+1].x) / 2);
                    break;
                }
            }
        }
    }

}