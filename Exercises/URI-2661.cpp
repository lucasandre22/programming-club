#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define ll long long
vector<int> primes;

void computePrimes(int n) {
    int size = sqrt(n);
    primes.push_back(2);
    for(int i = 3; i < size; i++) {
        int isPrime = 1;
        int r = sqrt(i);
        for(int j = 0; j < primes.size() && primes[j] <= r; j++) {
            if(i % primes[j] == 0) {
                isPrime = 0;
                break;
            }
        }
        if(isPrime)
            primes.push_back(i);
    }
}

int main(void) {
    ll n;
    scanf("%ld", &n);
    
    

 
    return 0;
}