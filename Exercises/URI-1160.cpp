#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://www.urionlinejudge.com.br/judge/en/problems/view/1160

int main(void) {
    int cases;
    int pop_a, pop_b;
    double growing_a, growing_b;
    int i;
    int teste = 100;
    teste += (int)(0.025f * teste);
    printf("i=%d teste=%d\n", (int)(1.9f), teste);
    scanf("%d", &cases);
    while(cases--) {
        scanf("%d %d %lf %lf", &pop_a, &pop_b, &growing_a, &growing_b);
        //growing_a /= 100.f;
        //growing_b /= 100.f;
        for(i = 1; pop_a < pop_b && i < 101; i++) {
            //pop_a += (int)(growing_a * pop_a);
            pop_a += (int)(pop_a * 100 / growing_a);
            //pop_b += (int)(growing_b * pop_b);
            pop_b += (int)(pop_b * 100 / growing_b);
            //printf("Result=%d should be=%lf\n", pop_a, ((double) pop_a + (growing_a * pop_a)));
        }

        if(i < 101) {
            printf("%d anos.\n", i);
        } else {
            printf("Mais de 1 seculo.\n");
        }
    }

    return 0;
}