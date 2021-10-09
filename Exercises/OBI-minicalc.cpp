#include <bits/stdc++.h>
#include <iostream>

#define ll long long

using namespace std;

//https://olimpiada.ic.unicamp.br/pratique/pj/2008/f2/minicalc/

int main(void) {
    int n, d, q;
    int max = 1;
    scanf("%d %d %d", &n, &d, &q);
    for(int i = 2; i <= min(d,q); i++) {
        if(d % i == 0 && q % i == 0) {
            max = i;
        }
    }

    if(((float)d/(float)max >= n || (float)q/(float)max >= n) || max == 1 && d == 1 && q == 1) {
        printf("IMPOSSIVEL\n");
    } else {
        printf("%d %d", d/max, q/max);
    }

    return 0;
}