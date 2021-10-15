#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<string> words;
vector<int> lala;

int main(void) {
    string word;
    int total = 0;
    int n;
    int days = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> word;
        word = word.substr(word.find(".") + 1, word.size());
        total += stoi(word) % 100;
        days += (total != 0);
    }
    printf("%d\n", days);

    return 0;
}

/**
 * para ler $2.00 e pegar só o 00, posso fazer direto no scanf:
 * scanf("$%d.%d", &n, &m), porém, tenho que ler o primeiro %d, mesmo que não for usar
 * para dar scape de um '\n' no buffer no scanf
 * scanf(" %d.%d");
**/