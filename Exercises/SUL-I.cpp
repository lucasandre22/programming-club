#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define DIV 1300031
#define MAX 21
int v[MAX];
int vi[MAX];

int compare (const void * a, const void * b){
  return ( *(int*)a - *(int*)b );
}


int main(void) {
    int n,m,o;
    int i;
    int j;
    int total_papeis = 0;
    
    while(scanf("%d %d %d", &n, &m, &o), n) {
        for(i = 0; i < o; i++) {
            scanf("%d", &v[i]);
        }
        qsort(v, o, sizeof(int), compare);
        for(i = 0; i < o; i++) {
            for(j = i+1; j < o && v[j] != 0; j++) {
                if(v[j] % v[i] == 0) {
                    v[j] = 0;
                }
            }
        }
        for(i = 0, j = 0; i < o; i++)
            if(v[i] != 0)
                vi[j++] = v[i];
        o = j;

        for(i = n; i <= m; i++) {
            if(i <= vi[o-1])
                for(j = 0; j < o; j++) {
                    if(i < vi[j]) break;
                    if((i % vi[j]) == 0) {
                        total_papeis += i;
                        if(total_papeis >= DIV)
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