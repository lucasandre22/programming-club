#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://www.urionlinejudge.com.br/judge/en/problems/view/1133

int main(void) {
    int x,y;
    int rest;
    scanf("%d %d", &x, &y);
    if(x > y) 
        swap(x,y);
    if(x > 0)
        for(int i = x+1; i < y; i++) {
            rest = i % 5;
            if(rest == 2 || rest == 3)
                printf("%d\n", i);
        }

    return 0;
}