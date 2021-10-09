#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://olimpiada.ic.unicamp.br/pratique/pj/2019/f1/idade/

int main(void) {
    int m, a, b, maior;
    scanf("%d", &m);
    scanf("%d", &a);
    scanf("%d", &b);
    maior = a > b ? a : b;
    maior = (m-(a+b)) > maior ? (m-(a+b)) : maior;
    printf("%d\n", maior);
    return 0;
}