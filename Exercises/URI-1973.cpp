#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://www.urionlinejudge.com.br/judge/en/problems/view/1973

int main(void) {
    vector<int> array;
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        sum += a;
        array.push_back(a);
    }
    int total = 0;
    for(int i = 0; i < array.size() && i >= 0; i) {
        int was = array[i];
        if(array[i] != 0) {
            array[i]--;
            total++;
        }
        printf("%d was %d movin to ->", i, was);
        if(was % 2 == 0)
            i--;
        else
            i++;
        printf("%d\n",i);
    }
    printf("%d %d", total, sum-total);

    return 0;
}