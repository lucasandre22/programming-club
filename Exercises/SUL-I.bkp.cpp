#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define DIV 1300031
#define MAX 21
int v[MAX];
int vi[MAX];

int main(void) {
    int n,m,o;
    int i;
    int j;
    int total_papeis = 0;
    int aux;

    while(scanf("%d %d %d", &n, &m, &o), n) {
        for(i = 0; i < o; i++) {
            scanf("%d", &v[i]);
        }
        qsort(v, o, sizeof(v));

        for(i = 0; i < o; i++) {
            for(j = i; j < o && v[j] != 0; j++) {
                if(v[i] % v[j] == 0)
                    v[j] = 0;
            }
        }
        for(i = 0, j; i < o; i++)
            if(v[i] != 0)
                vi[j++] = v[i];
        o = j;

        for(i = n; i <= m; i++) {
            for(j = 0; j < o; j++) {
                if((i % v[j]) == 0) {
                    total_papeis += i;
                    total_papeis %= DIV;
                    break;
                }
            }
        }
        printf("%d\n", total_papeis);
        total_papeis = 0;
    }
    return 0;
}