#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://www.urionlinejudge.com.br/judge/pt/problems/view/1030
#define MAX 11234
int v[MAX];

int main(void) {
    int cases;
    int n, k, l, i;
    scanf("%d", &cases);
    int p = cases;
    int ans;
    int current_pos;
    while(cases--) {
        scanf("%d %d", &n, &k);
        for(i = 1; i <= n; i++) {
            v[i] = 1;
        }
        current_pos = k;
        v[current_pos] = 0;
        for(i = n-1; i > 1; i--) {
            int total = 0;
            for(l = current_pos; total != k; l++) {
                if(l > n) {
                    l = 1;
                }
                if(v[l] == 1) {
                    total++;
                    if(total == k) {
                        break;
                    }
                }
            }
            current_pos = l;
            v[current_pos] = 0;
        }
        for(ans = 1; ans <= n; ans++) {
            if(v[ans]) {
                break;
            }
        }
        printf("Case %d: %d\n", (p - cases), ans);
    }

    return 0;
}