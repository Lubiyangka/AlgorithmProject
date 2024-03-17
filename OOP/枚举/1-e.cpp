#include<iostream>
#include<cstring>
using namespace std;

int a[9], ans[9];
char str[9][10] = {"ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
int Map[10][10];



int main(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < strlen(str[i]); j++){
            Map[str[i][j] - 'A'][i] = 1;
        }
    }

    for(int i = 0; i < 9; i++){
        cin>>a[i];
        a[i] = (4 - a[i]) % 4;
    }

    int i , j , k , l , temp , sum ;
    for(i = 0 , k = 0 ; i < 9 , k < 9 ; i++ , k++) {
        for(j = i ; j < 9 ; j++) {
            if( Map[j][k] ) break ;
        }
        if( j >= 9 ) {
            i-- ;
            continue ;
        }
        if( i != j ) {
            for(l = k ; l < 9 ; l++)
                swap(Map[i][l],Map[j][l]) ;
            swap(a[i],a[j]) ;
        }
        for(j = i+1 ; j < 9 ; j++) {
            if( !Map[j][k] ) continue ;
            temp = Map[j][k] ;
            for(l = k ; l < 9 ; l++) {
                Map[j][l] = Map[i][l]*temp - Map[j][l]*Map[i][k] ;
                Map[j][l] = (Map[j][l]%4+4)%4 ;
            }
            a[j] = a[i]*temp - a[j]*Map[i][k] ;
            a[j] = (a[j]%4+4)%4 ;
        }
    }
    sum = 0 ;
    for(i = 8 ; i >= 0 ; i--) {
        for(j = i+1 ; j < 9 ; j++) {
            a[i] -= ans[j]*Map[i][j] ;
            a[i] = (a[i]%4+4)%4 ;
        }
        for(j = 0 ; j < 4 ; j++)
            if( Map[i][i]*j%4 == a[i] )
                ans[i] = j , sum += j ;
    }
    for(i = 0 ; i < 9 ; i++) {
        while( ans[i]-- ) {
            sum-- ;
            if( sum )
                cout<<i+1<<" ";
            else
                cout<<i+1<<endl;
        }
    }
}


