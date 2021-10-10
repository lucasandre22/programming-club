#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int rest(int i, int j) {
    if(j != 0 && j != i)
        return rest(j, i % j);
    return i;
}

int main(void) {
    int a,b,c;

    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);

        printf("tripla");
        if(pow(a,2) == (pow(b,2) + pow(c,2)) || 
        pow(b,2) == (pow(a,2) + pow(c,2)) || 
        pow(c,2) == (pow(b,2) + pow(a,2))) {
            printf(" pitagorica");
            int minimum = min(a, b);
            int middle = a > b ? a : b;
            int resto = rest(minimum, c);
            if(resto == 1 && rest(minimum, b) == 1) {
                printf(" primitiva");
            }
        }
        printf("\n");
    }
    return 0;
    
}