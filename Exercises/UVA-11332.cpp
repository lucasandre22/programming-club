#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://vjudge.net/problem/UVA-11332

int getEachDigitSum(int n, int sum) {
    if (n % 10 == n) {
        return sum + (n % 10);
    }
    sum += n % 10;
    n /= 10;
    return getEachDigitSum(n, sum);
}

int main(void) {
    int n, a;
    scanf("%d", &n);
    while(n != 0) {
        a = n;
        while(a >= 10) {
            a = getEachDigitSum(a, 0);
        }
        printf("%d\n", a);
        scanf("%d", &n);
    }
    
    return 0;
}

/*int main(void) {
    int n, a;
    while(scanf("%d", &n), n) {       < --------------------------------- interessante
        a = n;
        while(a >= 10) {
            a = getEachDigitSum(a, 0);
        }
        printf("%d\n", a);
        scanf("%d", &n);
    }
    
    return 0;
}*/