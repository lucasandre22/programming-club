#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://atcoder.jp/contests/abc196/tasks/abc196_b

int main(void) {
    string c;
    cin >> c;
    for(int i = 0; i < c.size(); i++) {
        if(c[i] == '.') {
            c.resize(i+1);
            cout << c;
            break;
        }
    }

    return 0;
}