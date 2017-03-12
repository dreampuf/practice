//
// Created by XinXin Huang on 13/03/2017.
//

#include "stdio.h"

#define IMAX 2000

void SortIt(int a[], int alen, int *count) {
    int i, j, temp;
    for (i=1; i < alen; i++) {
        temp = a[i];
        j = i - 1;
        for(; j >= 0 && a[j] > temp; j--) {
            a[j+1] = a[j];
            (*count) ++;
        }
        a[j+1] = temp;
    }
}

int main() {
    int a[IMAX] = {};
    int i=0, alen=0, count=0;
    while (i < IMAX) {
        scanf("%d", &a[i]);
        if (a[i++] == -9999) { break; }
    }
    alen = i-1;
    SortIt(a, alen, &count);
    for(i=0; i < alen; i ++) {
        printf("%d ", a[i]);
    }
    printf("\nCompare Count: %d\n", count);
    return 0;
}