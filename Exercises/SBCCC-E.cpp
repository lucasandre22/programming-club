#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    int n, i, total_time = 0, atual, direction;
    vector<int> array[2];
    int tempo_total, tempo_atual;
    int menor;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &atual, &direction);
        array[direction].push_back(atual);
    }
    if(array[0].size() == 0) {
        tempo_total = array[1][0];
    }
    else if(array[1].size() == 0) {
        tempo_total = array[0][0];
    }
    else {
        tempo_total = array[0][0] < array[1][0] ? array[0][0] : array[1][0];
        menor = array[0][0] < array[1][0] ? 0 : 1;
    }

    int atual, anterior;
    int tentativa_atual;
    int tentativa_anterior;
    int diferenca;
    for(i = 0; i < n; i++) {
        tentativa_atual = 10;
        while(array[menor][0] - anterior < 10) {
            diferenca = atual - tempo_anterior;
            if(diferenca > 10) {
                break;
            }
            count++;
            current_try += diferenca;
            array[menor].erase(array[menor].begin());
        }



        menor > 0 ? menor-- : menor++;
    }
    
    
    printf("%d\n", total_time);
    return 0;
}