//
// Created by XinXin Huang on 13/03/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    struct node *leftChild;
    struct node *rightChild;
    char data;
}BiTreeNode, *BiTree;

int createBiTree(BiTree * T, char * pdata)
{
    char c;
    c = *pdata;
    if(('.' == *pdata) || ('\0' == *pdata) )
        *T = NULL;
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode)) ;
        (*T)->data = c;
        pdata++;
        createBiTree(&((*T)->leftChild), pdata);
        pdata++;
        createBiTree(&((*T)->rightChild), pdata);
    }
    return 0;
}

void inOder(BiTree p)
{
    if (NULL == p)
    {
        return ;
    }
    inOder(p->leftChild);
    printf("%c", p->data);
    inOder(p->rightChild);
}

int TreeDepth(BiTreeNode *pTreeNode)// 根节点的深度为1
{
    int nLeft=0, nRight=0;

    if(!pTreeNode)
        return 0;

    nLeft = TreeDepth(pTreeNode->leftChild);

    nRight = TreeDepth(pTreeNode->rightChild);

    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}

int LeafCount(BiTreeNode *pTreeNode)// 叶子只有入度没有出度
{
    if (!pTreeNode)
    {
        return 0;
    }
    else if (!pTreeNode->leftChild && !pTreeNode->rightChild)
    {
        return 1;
    }
    else
    {
        return (LeafCount(pTreeNode->leftChild) + LeafCount(pTreeNode->rightChild));
    }
}

// 用户输入前序序列，若无左节点或无右节点则输入点，则输入的序列可以认为为 满二叉树 非全二叉树，则除根节点 左右节点数相同。
int main()
{
    char tData[50] = {0};
    BiTree T;
    // 区分出左右分支
    char leftData[50] = {0},rightData[50] = {0};
    printf("请输入先序序列(无左节点或无右节点则输入点)：\n");
    scanf("%s", tData);

    memcpy(leftData, tData+1, strlen(tData)/2);
    memcpy(rightData, tData+1+strlen(tData)/2, strlen(tData)/2);
    T = (BiTree)malloc(sizeof(BiTreeNode)) ;
    T->data = *tData;
    createBiTree(&(T->leftChild), leftData);
    createBiTree(&(T->rightChild), rightData);

    printf("\n");
    inOder(T);
    printf("\n");
    printf("TreeDepth:%d\n", TreeDepth(T));
    printf("LeafCount:%d\n", LeafCount(T));

    // AB.D..CE...
    return 0;
}

