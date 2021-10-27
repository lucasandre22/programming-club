#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(int position, int n, char first, char second) {
    if(n == 1 || position == 0 || position == n-1) {
        printf("A -> C\n");
        return;
    }
    if(position == n-1) {

    }
    if(position > 1) {
        solve(n - operation, operation);
    }
    printf("%c -> %c\n");

    printf("A -> C\n");
}

void hanoi(int n) {
    solve(0, n, 'A', 'C');
}

int main(void) {
    int n;
    scanf("%d", &n);
    solve(n);
    return 0;
}