#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define SIZE 112345

int binary(int* array, int value, int left, int right) {
    int middle = (left+right)/2;
    if(left <= right) {
        if(array[middle] > value) {
            return binary(array, value, left, middle + 1);
        } else if(array[middle] < value) {
            return binary(array, value, middle - 1, right);
        }
    }
    return array[middle] == value ? middle : -1;
}

int binary_search(int* array, int value, int size) {
    return binary(array, value, 0, size-1);
}

int main(void) {
    int array[SIZE];
    int toSearch = 31321;
    for(int i = 0; i < SIZE; i++) {
        array[i] = i;
    }
    printf("i: %d\n", binary_search(array, toSearch, SIZE));

    return 0;
}