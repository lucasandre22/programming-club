#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define MAX 123

int vet[MAX];

int main(void) {
    int C;
    int soma = 0;
    int i = 0;
    scanf("%d", &C);
    vet[0] = 100;
    for(i = 1; i < C+1; i++) {
        scanf("%d", &vet[i]);
        vet[i] = vet[i-1] + vet[i];
    }
    for(i = 0; i < C+1; i++) {
        if(vet[i] > vet[0])
            vet[0] = vet[i];
    }
    printf("%d\n", vet[0]);

    return 0;
}