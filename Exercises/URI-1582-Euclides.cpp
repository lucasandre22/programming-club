#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int rest(int i, int j) {
    if(j > 0)
        return rest(j, i % j);
    return i;
}

int main(void) {
    int a,b,c;

    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);

        printf("tripla");
        if(pow(c,2) == (pow(a,2) + pow(b,2))) {
            printf(" pitagorica");
            if(rest(a, rest(b, c)) == 1) {
                printf(" primitiva");
            }
        }
        printf("\n");
    }
    return 0;
    
}