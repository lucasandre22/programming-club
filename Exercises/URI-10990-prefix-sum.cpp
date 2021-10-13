#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX 2123456

/*
prefix-sum:
dado um vetor e dado o problema de calcular a soma de todas as posições do mesmo;
pre-computa num outro vetor o prefixo de cada posição: posição i é a soma de todos os valores até 1
e então pra calcular a soma de todos entre a posição <-i e j->, basicamente tiro a soma do j com a do i 

for(int i = 2; i < MAX; i++) {
        soma[i] = i+soma[i-1];
    }
*/


//professor solution
#define ll long long
ll soma[MAX];
int dephi[MAX];
int phi[MAX];

void sieve() {
    for(int i = 2; i < MAX; i++) phi[i] = i;
    for(int i = 2; i < MAX; i++)
        if(i == phi[i]) 
            for(int j = i; j < MAX; j += i)
                phi[j] -= phi[j]/i;

}

int main(void) {
    int ncases, n, m;
    soma[1] = dephi[1] = 0;
    sieve();
    for(int i = 2; i < MAX; i++) {
        dephi[i] = dephi[phi[i]] + 1;
    }
    for(int i = 2; i < MAX; i++) {
        soma[i] = soma[i-1]+dephi[i];
    }
    scanf("%d", &ncases);
    while(ncases--) {
        scanf("%d %d", &m, &n);
        printf("%lld\n", soma[n] - soma[m-1]);
    }

    return 0;
}