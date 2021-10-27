#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define MAX 50
double a[MAX];

int main(void) {
    int cases;
    int total_balls;
    int pegs;
    int i, j;
    int s;
    int flag = 0;
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d", &pegs);
        memset(a, 0, sizeof(a));
        total_balls = 0;
        for(i = 1; ; i++, total_balls++) {
            for(j = 0; j < pegs; j++) {
                s = sqrt(a[j]+i);
                if(!a[j] || s * s == (a[j]+i)) {
                    a[j] = i;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                break;
            flag = 0;
        }

        printf("%d\n", total_balls);
    }

    return 0;
}