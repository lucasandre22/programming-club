#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    int a,b,c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        printf("tripla");
        if(pow(a,2) == (pow(b,2) + pow(c,2)) || 
        pow(b,2) == (pow(a,2) + pow(c,2)) || 
        pow(c,2) == (pow(b,2) + pow(a,2))) {
            printf(" pitagorica");
            int max = 1;
            int m = a < b ? a : b;
            m = m < c ? m : c;
            for(int i = 2; i <= m; i++) {
                if(a % i == 0 &&
                b % i == 0 && 
                c % i == 0) {
                    max = i;
                    break;
                }
            }
            if(max == 1) {
                printf(" primitiva");
            }
        }
        printf("\n");
    }
    return 0;
}