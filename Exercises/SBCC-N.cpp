#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX 112345

int vagas_ano[MAX];

int vagas[MAX];

int vetor_vagas_indice[MAX];

int main(void) {
    int anos, competidores, i;
    int ultima_participacao;
    int colocacao_ano;
    int seguiu_resultado;
    vector<pair<int,int>> vetor;
    pair<int,int> aux;

    scanf("%d %d", &anos, &competidores);

    for(i = 0; i < anos; i++) {
        scanf("%d", &vagas_ano[i]);
        aux.first = vagas_ano[i];
        aux.second = 0;
        vetor.push_back(aux);
    }
    sort(vetor.begin(), vetor.end());
    for(i = 0; i < anos; i++) {
        vetor[i].second = anos-i;
    }

    for(i = 0; i < competidores; i++) {
        scanf("%d %d %d", &ultima_participacao, &colocacao_ano, &seguiu_resultado);

;
        
    }

    return 0;
}