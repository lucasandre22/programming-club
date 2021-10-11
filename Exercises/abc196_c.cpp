#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://atcoder.jp/contests/abc196/tasks/abc196_c

int isPalindrome(string s) {
    for(int i = 0; (i+(s.size()/2)) < s.size(); i++) {
        if(s[i] != s[(i+(s.size()/2))])
            return 0;
    }
    return 1;
}



int main(void) {
    int n, ans = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        string a = to_string(i);
        if(a.size() % 2 == 0) {
            ans += isPalindrome(a);
        }
    }
    cout << ans;


    return 0;
}
