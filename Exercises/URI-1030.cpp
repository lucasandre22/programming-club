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
    int left;
    while(cases--) {
        scanf("%d %d", &n, &k);
        memset(v, 1, (n+1)*sizeof(v[0]));
        left = n-1;
        current_pos = k;
        v[current_pos] = 0;
        for(i = n-1; i > 1; i--) {
            int total = 0;
            int pos = current_pos;
            int toWalk = (left % k);
            while(total != toWalk) {
                if(pos > n) pos = 1;
                if(v[pos]) {
                    total++;
                    if(total != toWalk)
                        break;
                }
                pos++;
            }
            printf("c=%d\n", current_pos);
            current_pos = pos;
            v[current_pos] = 0;
            left--;
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