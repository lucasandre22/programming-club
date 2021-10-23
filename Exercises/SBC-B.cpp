#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
#define MAX 8
int vet[MAX];

void calc_fatorial()
{
    vet[0] = 1;
    for(int i = 1; i < MAX; i++) {
        vet[i] = (i+1) * vet[i-1];
    }
}

int main(void) {
    int n;
    int acumulado = 0;
    int i;
    scanf("%d", &n);
    calc_fatorial();
    while(n >= 1) {
        for(i = MAX-1; i >= 0 && vet[i] > n; i--) {}
        n -= vet[i];
        acumulado++;
    }
    printf("%d\n", acumulado);
    return 0;
}