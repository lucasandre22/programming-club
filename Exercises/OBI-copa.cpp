#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://olimpiada.ic.unicamp.br/pratique/pj/2018/f2/copa/

int solve(int a, int b, int c, int i) {
    i++;
    if(a <= c/2 && b > c/2) {
        return i;
    } else if(a >= c/2 && b > c/2) {
        return solve(a, b, c+(c/2)+1, i);
    } else {
        return solve(a, b, c-(c/2)-1, i);
    }
}

int teste(int a, int b) {
    if(a != b) {
        return 1 + teste(a/2, b/2);
    }
    return 0;
}

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    switch(teste(a-1, b-1)) {
        case 1: printf("oitavas\n"); break;
        case 2: printf("quartas\n"); break;
        case 3: printf("semifinais\n"); break;
        case 4: printf("finais\n"); break;
    }
    return 0;
}