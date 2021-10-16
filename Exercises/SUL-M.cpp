#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int letras[60];

int main(void) {
    int m;
    int i, j;
    string nome;
    int count;
    memset(letras, 0, sizeof(letras));
    letras[0] = 1; letras[4] = 1; letras[8] = 1; letras[14] = 1; letras[20] = 1;
    letras[32] = 1; letras[36] = 1; letras[40] = 1; letras[46] = 1; letras[52] = 1;

    scanf("%d", &m);
    for(i = 0; i < m; i++) {
        cin >> nome;
        count = 0;
        for(j = 0; j < nome.size() && count < 3; j++) {
            if(!letras[nome[j] - 65]) {
                count++;
            } else {
                count = 0;
            }
        }
        if(count >= 3) {
            cout << nome << " nao eh facil\n";
        } else {
            cout << nome << " eh facil\n";
        }
    }
    return 0;
}