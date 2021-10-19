/*#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(void) {
    string numeros;
    int numero_atual;
    vector<int> vetor;
    int a = 0;
    size_t b = 0;
    getline(cin, numeros);
    while(b != string::npos) { //vai rodar enquanto eu conseguir dividir a string de entrada com espaços
        b = numeros.find(" ");
        numero_atual = std::stoi(numeros.substr(a, b));
        vetor.push_back(numero_atual);
        numeros = numeros.substr(b+1, numeros.size());
    }
    cout << "Vetor contem os numeros:" << endl;
    for(int a : vetor) {
        cout << a << ' ';
    }
    return 0;
}*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void) {
    string numeros;
    int numero_atual;
    vector<int> vetor;
    int a = 0;
    size_t b = 0;
    int variavelInutil;
    cin >> variavelInutil;
    cin.ignore();
    getline(cin, numeros);
    while(b != string::npos && b != numeros.size()) {
        b = numeros.find(" ");
        numero_atual = stoi(numeros.substr(a, b));
        vetor.push_back(numero_atual);
        numeros = numeros.substr(b+1, numeros.size());
    }
    int tamVetor = vetor.size();
    cout << vetor[3] << " ";
    for (int i=0; i<(tamVetor-1); i++){
        cout << vetor[i] << " ";
    }
}