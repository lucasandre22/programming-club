#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    int n, i, total_time = 0;
    int c_time;
    int current_try;
    int tempo_anterior;
    int direction_want;
    vector<int> array[2];
    int menor;
    int atual;
    int diferenca;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d %d", &c_time, &direction_want);
        array[direction_want].push_back(c_time);
    }
    
    int flag_first = 1;
    int count;
    int save;
    for(i = 0; i < n; i += count) {
        count = 0;
        if(i == 0) {
            if(array[0].size() == 0) {
                menor = 1;
            }
            else if(array[1].size() == 0) {
                menor = 0;
            }
            else {
                menor = array[0][0] < array[1][0] ? 0 : 1;
            }
        } else {
            menor = menor == 1 ? 0 : 1;
            save = atual;
        }
        int another_flag = 1;
        current_try = 10;
        if(array[menor].size() > 1)
            for(atual = array[menor][0]; !array[menor].empty(); atual = array[menor][0]) {
                if(flag_first || another_flag) {
                    tempo_anterior = atual;
                    count++;
                    if(flag_first)
                        total_time += atual;
                    flag_first = 0;
                    another_flag = 0;
                    array[menor].erase(array[menor].begin());
                    continue;
                }
                diferenca = atual - tempo_anterior;
                if(diferenca > 10) {
                    break;
                }
                count++;
                current_try += diferenca;
                array[menor].erase(array[menor].begin());
                tempo_anterior = atual;
            }
        else
            count++;
        total_time += current_try;
    }
    printf("%d\n", total_time);
    return 0;
}