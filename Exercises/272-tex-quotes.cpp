#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=208

int main(void) {
    string s;
    string output;
    string aux;
    while(getline(cin, aux)) {
        aux.append("\n");
        s.append(aux);
    }
    output.resize(s.size());

    for(int i = 0, m = 0; i < s.size(); i++, m++) {
        if(s[i] == 34) {
            output.push_back('`');
            output.push_back('`');
            m+=2;
            int j;
            for(j = i+1; j < s.size() && s[j] != 34; j++) {
                output.push_back(s[j]);
            }
            i = j;
            output.push_back('\'');
            output.push_back('\'');
            m+=2;
            //output[m++] = '\'';
            //output[m++] = '\'';
        } else {
            output.push_back(s[i]);
        }
    }
    cout << output;
    return 0;
}