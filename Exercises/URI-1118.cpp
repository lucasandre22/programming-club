#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://www.urionlinejudge.com.br/judge/en/problems/view/1118

int main(void) {
    float n1, n2;
    int choice;
    do {
        scanf("%f", &n1);
        while(n1 < 0.0 || n1 > 10.0) {
            printf("nota invalida\n");
            scanf("%f", &n1);
        }
        scanf("%f", &n2);
        while(n2 < 0.0 || n2 > 10.0) {
            printf("nota invalida\n");
            scanf("%f", &n2);
        }
        printf("media = %.2f\n", (n1+n2)/2.0f);
        printf("novo calculo (1-sim 2-nao)\n");
        scanf("%d", &choice);
        while(choice < 1 || choice > 2) {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &choice);
        }
        
    } while(choice != 2);

    return 0;
}