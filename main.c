#include "stdio.h"
#include "stdlib.h"


typedef struct node{
    int data;
    struct node *next;
} ListNode;

int main(int argc, char *argv[]) {
    ListNode *ls = (ListNode *)malloc(sizeof(ListNode));
    ListNode *root = ls;

    int i = 5;
    int n = 0;
    int c[100] = {};
    while (i-- > 0) {
        scanf("%d", &n);
        ls->data = n;
        printf("Your input is: %d\n", n);
        ls->next = (ListNode *)malloc(sizeof(ListNode));
        ls = ls->next;
    }

    ls = root;
    while (ls->next != NULL) {
        printf("I: %d\n", ls->data);
        ls = ls->next;
    }
    printf("Hello world");
    return 0;
}