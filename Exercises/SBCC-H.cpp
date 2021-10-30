#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    int n, k, i;
    int a, b;
    vector<pair<int, int>> vetor;
    pair<int, int> aux;

    scanf("%d %d", &n, &k);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        aux.first = a; aux.second = b;
        vetor.push_back(aux);
    }
    for(i = 0; i < n; i++) {
        if(vetor[vetor[i].first-1].second != vetor[i].second) {
            printf("N\n");
            return 0;
        }
    }
    printf("Y\n");
    return 0;
}