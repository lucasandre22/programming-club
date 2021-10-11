#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void preenche(int **matriz, int i, int j) {
    if(matriz[i][j] != 0)
        matriz[i][j]++;
    if(matriz[i][j+1] != 0)
        matriz[i][j+1]++;
    if(matriz[i+1][j] != 0)
        matriz[i+1][j]++;
    if(matriz[i+1][j+1] != 0)
        matriz[i+1][j+1]++;
}

int main(void) {
    int n,m;
    int **matriz;
    int operations = 0;
    vector<int> v;
    
    scanf("%d %d", &n, &m);
    matriz = (int**)malloc(n*sizeof(int*));
    for(int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(m*sizeof(int));
        for(int j = 0; j < m; j++) {
            int aux;
            scanf("%d", &aux);
            matriz[i][j] = aux;
        }
    }
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m-1; j++) {
            if(matriz[i][j] != 0 && matriz[i][j+1] != 0 && matriz[i+1][j] != 0 && matriz[i+1][j+1] != 0) {
                operations++;
                v.push_back(i+1);
                v.push_back(j+1);
                preenche(matriz,i,j);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] == 1) {
                printf("-1\n");
                return 0;
            }
        }
    }
    printf("%d\n", operations);
    for(int i = 0; i < v.size(); i+=2) {
        printf("%d %d\n", v[i], v[i+1]);
    }
    

    return 0;
}