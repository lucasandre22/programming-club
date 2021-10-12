#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
para subtração, sempre soma o modulo antes:
se é modulo de 7
(3 + 5 - 4) % 7 --> erro
(3 + 5 + 7 - 4) % 7 --> certo

*/

//https://www.urionlinejudge.com.br/judge/en/problems/view/1580

#define DIV 1000000007
#define ll long long

ll expo(ll n) {
    ll a = n;
    while(n > 1) {
        a = (a*(n-1)) % DIV;
        n--;
    }
    return a;
}

ll binary_expo(ll a, ll n) {
    if(n > 1) {
        if(!(n & 1)) {
            ll b = binary_expo(a, n/2);
            return (b * b) % DIV;
        }
        return (a * binary_expo(a, n-1)) % DIV;
    }
    return 1;
}

/*int main() {
    printf("%lld", binary_expo(4));
}*/

int main(void) {
    char word[1123];
    ll letter_frequency[26];
    int total = 0;
    ll fact[1000];
    fact[0] = 1;
    for(int i = 1; i < 1000; i++) 
        fact[i] = (fact[i-1] * i) % DIV;

    while(scanf(" %s", word) != EOF) {
        memset(letter_frequency, 0, sizeof(letter_frequency));
        total = strlen(word);
        for(int i = 0; word[i] < total; i++) {
            letter_frequency[(word[i]-65)]++; // ou (word[i]-'A')
            /*if(letter_frequency[(word[i]-65)] > 1) {
                u++;
            } 
            total++;*/
        }
        ll a = fact[total];
        ll b = 1;
        for(int i = 0; i < 26; i++) {
            //if(letter_frequency[i] > 1) {
                b *= fact[letter_frequency[i]];
                b %= DIV;
            //}
        }
        
        b = binary_expo(b, DIV - 2);
        printf("%lld\n", (a * b) % DIV);
    }

    return 0;
}