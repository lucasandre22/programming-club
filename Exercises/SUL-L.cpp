#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define EPS 1e-2

int main(void) {
    int n;
    float l, q;
    vector<string> nomes;
    string nome;
    int rodada = 0;

    scanf("%d %f %f", &n, &l, &q);
    for(int i = 0; i < n; i++) {
        cin >> nome;
        nomes.push_back(nome);
    }

    while(true) {
        rodada++;
        l -= q;
        float temp = (l - q);
        if(temp - EPS <= 0.0f) {
            break;
        }
    }
    cout << nomes[(rodada % n)];
    printf(" %.1f\n", l);
    return 0;
}
