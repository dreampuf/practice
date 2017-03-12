//
// Created by XinXin Huang on 13/03/2017.
//

#include "stdio.h"

#define IMAX 1000

int BinarySearch(int a[], int key, int low, int high) {
    int mid;
    if (low <= high) {
        mid = (low+high)/2;
        if (a[mid] == key) {
            return 1;
        }
        if (a[mid] > key) {
            return BinarySearch(a, key, low, mid-1);
        } else {
            return BinarySearch(a, key, mid+1, high);
        }
    }
    return 0;
}

void SortIt(int a[], int alen) {
    int i, j, temp;
    for (i=1; i < alen; i++) {
        temp = a[i];
        j = i - 1;
        for (; j >= 0 && a[j] > temp; j--) {
            a[j+1] = a[j];
        }
        a[j + 1] = temp;
    }
}

int RemoveRepeat(int a[], int alen) {
    int i=0, j=0;
    for (i=0; i< alen-1; i++) {
        while (a[i] == a[i+1]) {
            i ++;
        }
        a[j++] = a[i];
    }
    if (a[j-1] != a[i]) {
        a[j++] = a[i];
    }
    return j;
}

int DifferenetSet(int a[], int alen, int b[], int blen, int c[]) {
    int i = 0, j = 0;
    for (i=0; i<alen; i++) {
        if (!BinarySearch(b, a[i], 0, blen)) {
            c[j++] = a[i];
        }
    }
    return j;
}

int InsertSet(int a[], int alen, int b[], int blen, int c[]) {
    int i=0, j=0;
    for (i=0; i <= alen; i++) {
        if (BinarySearch(b, a[i], 0, blen)) {
            c[j++] = a[i];
        }
    }
    return j;
}

int UnionSet(int a[], int alen, int b[], int blen, int c[]) {
    int i=0, j=alen;
    memcpy(c, a, alen*sizeof(int));
    for(i=0; i < blen; i++) {
        if (!BinarySearch(a, b[i], 0, alen)) {
            c[j++] = b[i];
        }
    }
    return j;
}

void printA(int a[], int alen) {
    for (int i = 0; i < alen; i ++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[IMAX] = {};
    int b[IMAX] = {};
    int c[IMAX*2] = {};
    int ai = 0, ar = 0, bi = 0, br = 0, cr = 0;
    while (ai < IMAX) {
        scanf("%d", &a[ai]);
        if (a[ai] == -9999) {
            break;
        }
        ai ++;
    }
    while (bi < IMAX) {
        scanf("%d", &b[bi]);
        if (b[bi] == -9999) { break; }
        bi ++;
    }

    SortIt(a, ai);
    SortIt(b, bi);
    ar = RemoveRepeat(a, ai);
    br = RemoveRepeat(b, bi);
    printf("A:\n");
    printA(a, ar);
    printf("B:\n");
    printA(b, br);
    printf("A-B:\n");
    cr = DifferenetSet(a, ar, b, br, c);
    printA(c, cr);
    memset(c, 0, cr);
    printf("B-A:\n");
    cr = DifferenetSet(b, br, a, ar, c);
    printA(c, cr);
    memset(c, 0, cr);
    printf("A&B:\n");
    cr = InsertSet(a, ar, b, br, c);
    printA(c, cr);
    memset(c, 0, cr);
    printf("A|B:\n");
    cr = UnionSet(a, ar, b, br, c);
    printA(c, cr);
    memset(c, 0, cr);
}

