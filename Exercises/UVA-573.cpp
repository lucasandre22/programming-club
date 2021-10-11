#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//PROFESSOR SOLUTION

#define EPS 1e-9

int main(void) {
    int h,u,d,f;
    double pos, pen = 0, fa, tmp;
    int total_days;
    int flag;
    while(scanf("%d %d %d %d", &h, &u, &d, &f), h) {
        pos = 0; total_days = 0; flag = 0; fa = (f/100.) * u; pen = 0;

        do {
            tmp = u - pen;
            if(tmp > EPS)
                pos += tmp;
            pen += fa;
            if(pos >  h + EPS) 
                flag = 1;
            else
            {
                pos -= d;
                if(pos < -EPS) 
                    flag = 2;
            }
            total_days++;
        } while(!flag);
        printf(flag == 1 ? "success " : "failure ");
        printf("on day %d\n", total_days);
    }
    
    return 0;
}