#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
#define MAX 1123456

//https://www.urionlinejudge.com.br/judge/en/problems/view/1973
int a[MAX], flags[MAX];

int main(void) {
    int n;
    ll sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        flags[i] = 1;
    }
    ll total = 0;
    int i = 0;
    ll sheep = 0;
    while(i < n && i >= 0) {
        if(a[i] > 0)
            sheep++;
        int was = a[i];
        if(a[i] && flags[i]) {
            a[i]--;
            flags[i] = 0;
            total++;
        }
        if(was % 2 == 0)
            i--;
        else
            i++;
    }
    printf("%lld %lld\n", total, sum-sheep);

    return 0;
}