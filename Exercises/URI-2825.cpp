#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//https://www.urionlinejudge.com.br/repository/UOJ_2825_en.html
vector<string> words;
int words_array[52];
int words_array2[52];
/*if(i > 90) {
    i += 7;
    - 'A';
}*/

int main(void) {
    int nwords;
    int nwords_to_fix;
    string phrase;
    string word;
    scanf("%d", &nwords);
    for(int i = 0; i < nwords; i++) {
        string str;
        cin >> str;
        words.push_back(string(str));
    }
    scanf("%d", &nwords_to_fix);
    getline(cin, phrase);
    getline(cin, phrase);
    int a = 0;
    int b;
    string final_phrase;
    for(int i = 0; i < nwords_to_fix; i++) {
        if(i < nwords_to_fix-1)
            b = phrase.find(" ");
        else
            b = phrase.size();
        word = phrase.substr(a, b);
        memset(words_array, 0, 52*sizeof(words_array[0]));
        memset(words_array, 0, 52*sizeof(words_array2[0]));
        int position;
        for(int j = 0; j < (int)word.size(); j++) {
            position = word[j];
            if(position > 'Z')
                words_array[position-71]++;
            else
                words_array[position-65]++;
        }
        int toCompare;
        string current_word;
        int atual = 0;
        pair<int, int> word_position_count;
        word_position_count.first = 0;
        word_position_count.second = -1123;
        int substitutions = 0;
        int toDiminuir = 0;
        for(int j = 0; j < (int)words.size(); j++) {
            current_word = words[j];
            atual = 0;
            for(int k = 0; k < (int)current_word.size(); k++) {
                toCompare = current_word[k] > 'Z' ? (current_word[k]-71) : (current_word[k]-65);
                if(words_array[toCompare] != words_array2[toCompare]) {
                    atual++;
                    words_array2[toCompare]++;
                }
                if(current_word[k] != word[k])
                    substitutions++;
            }

            if((atual - substitutions - abs((int)current_word.size() - (int)word.size())) > word_position_count.second) {
                //cout << current_word << ' ' << (atual - substitutions) << " " << endl;
                word_position_count.first = j;
                word_position_count.second = atual - substitutions;
            }
            substitutions = 0;
            memset(words_array2, 0, 52*sizeof(words_array2[0]));
        }
        //final_phrase += words[word_position_count.first] + ' ';
        final_phrase += final_phrase.empty() ? words[word_position_count.first] : (' ' + words[word_position_count.first]);
        
        //toDiminuir += abs((int)words[word_position_count.first].size() - (int)word.size());

        //toDiminuir += abs(words[word_position_count.first] - phrase.substr(b+1, phrase.find(' ')));
        if(i != nwords_to_fix-1)
            phrase = phrase.substr(b+1, phrase.size());
    }
    cout << final_phrase << '\n';

    return 0;
}