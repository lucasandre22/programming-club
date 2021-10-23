#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", b < a ? 1 : (int)ceil(b/(a-1.f)));
    return 0;
}