#include <iostream>

int main()
{
    int x = 0, y = 0;
    std::cin >> x;
    while(x){
        y = y*10 + x%10;
        x/=10;
    }
    std::cout<<y;
}