#include <bits/stdc++.h>
#include <iostream>
using namespace std;

vector<string> words;
vector<int> lala;

int main(void) {
    string word;
    int total = 0;
    int n;
    int days = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        cin >> word;
        word = word.substr(word.find(".") + 1, word.size());
        total += stoi(word) % 100;
        if(total == 0) {
            days++;
        }
    }
    printf("%d\n", days);

    return 0;
}