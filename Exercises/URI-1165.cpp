#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//

int isPrime(int x, int d) {
    if(d >= x) {
        return 1;
    } else if(x % d == 0) {
        return 0;
    }
    return isPrime(x, ++d);
}
 
int main() {
    int n;
    int x;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        if(isPrime(x, 2))
            printf("%d eh primo\n", x);
        else
            printf("%d nao eh primo\n", x);
    }
 
    return 0;
}
