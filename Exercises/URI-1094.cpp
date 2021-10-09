#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    int n, a, t = 0;
    int co, ra, sa;
    char c;
    co = ra = sa = 0;
    scanf("%d", &n);

    while(n--) {
        scanf("%d %c", &a, &c);
        t += a;
        switch(c) {
            case 'C':
                co += a;
                break;
            case 'R':
                ra += a;
                break;
            case 'S':
                sa += a;
                break;
        }
        printf("%d %c\n", a, c);
    }
    printf("Total: %d cobaias\n", t);
    printf("Total de coelhos: %d\n", co);
    printf("Total de ratos: %d\n", ra);
    printf("Total de sapos: %d\n", sa);
    printf("Percentual de coelhos: %.2f %%\n", (double)co*100/t);
    printf("Percentual de ratos: %.2f %%\n", (double)ra*100/t);
    printf("Percentual de sapos: %.2f %%\n", (double)sa*100/t);

    return 0;
}