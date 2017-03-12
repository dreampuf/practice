//
// Created by XinXin Huang on 13/03/2017.
//
#include

#include

#include

void exit(int);

#define MAX 100

typedef struct node {

    char d;

    struct node *lchild, *rchild;

} Tnode;

void MKTree(char pre[], int pres, int pree, char in[], int is, int ie, Tnode **r) {

    int i;

    if (pres > pree || is > ie)

        *r = NULL;

    else {

        *r = malloc(sizeof(Tnode));

        for (i = is; i <= ie; i++)

            if (pre[pres] == in[i]) {

                MKTree(pre, pres + 1, pres + i - is, in, is, is + i - 1, &(*r)->lchild);

                MKTree(pre, pres + i + is + 1, pree, in, is + i + 1, ie, &(*r)->rchild);

                break;

            }

    }

}

void postorder(Tnode *r) {

    if (r) {

        postorder(r->lchild);

        postorder(r->rchild);

        printf("%c",r->d);

    }

}

int num(Tnode *r) {

    if (r == NULL)

        return 0;

    else if (r->lchild == NULL && r->rchild == NULL)

        return 1;

    else

        return num(r->lchild) + num(r->rchild);

}

int height(Tnode *r) {

    int h1, h2;

    if (r == NULL)

        return 0;

    else {

        h1 = height(r->lchild);

        h2 = height(r->rchild);

        return 1 + (h1 > h2) ? h1: h2;

    }

}

void main() {

    Tnode *r;

    char pre[MAX], in[MAX];

    printf("input preorder and inorder \n");
    gets(pre);
    gets(in);
    MKTree(pre, 0, strlen(pre) - 1, in, 0, strlen(in) - 1, &r);

    printf("The postorder is as follow：\n");

    postorder(r);

    printf("\n there are %d leaves in the tree\n", num(r));

    printf("h =%d\n", height(r));

}



