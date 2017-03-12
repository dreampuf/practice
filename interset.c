//
// Created by XinXin Huang on 13/03/2017.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000
// 冒泡排序
void Bubble_sort(int * arr,int n)
{
    int i=0, j=0, iTemp=0;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                iTemp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = iTemp;
            }
        }
    }
}
// 二分查找
int BinSearch(int arr[], int key, int low, int high)
{
    int mid;
    if(low <= high)
    {
        mid = (low + high)/2;
        // 查找到返回1
        if(arr[mid] == key)
        {
            return 1;
        }
        // 如果
        if(arr[mid] > key)
        {
            // 查找左分支
            return BinSearch(arr, key, low, mid-1);
        }
        else
        {
            // 查找右分支
            return BinSearch(arr, key, mid+1, high);
        }
    }
    return 0;
}
// 先排序后移除重复数据
int RemoveRepeatData(int arr[],int n)
{
    int i=0, j=0;
    for(i=0; i<n-1; i++)
    {
        while(arr[i] == arr[i+1])
        {
            i++;
        }
        arr[j++] = arr[i];
    }
    if(arr[j-1] != arr[i])
    {
        arr[j++] = arr[i];
    }
    return j;
}
// 差集
int differentSet(int a[], int an, int b[],int bn, int c[])
{
    int i=0, j=0;
    for(i=0; i<an; i++)
    {
        if(!BinSearch(b, a[i], 0, bn))
        {
            c[j++] = a[i];
        }
    }
    return j;
}
// 交集
int InsersectionSet(int a[], int an, int b[],int bn, int c[])
{
    int i=0, j=0;
    for(i=0; i<an; i++)
    {
        if(BinSearch(b, a[i], 0, bn))
        {
            c[j++] = a[i];
        }
    }
    return j;
}
// 并集
int UnionSet(int a[], int an, int b[],int bn, int c[])
{
    int i=0, j=0;
    memcpy(c, a, an*(sizeof(int)));
    j = an;
    for(i=0; i<bn; i++)
    {
        // 在a中查找b[i]是否存在 不存在则保存
        if(!BinSearch(a, b[i], 0, an))
        {
            c[j++] = b[i];
        }
    }
    return j;
}
int main(int argc,char * argv[])
{
    int a[MAX_SIZE] = {0};
    int b[MAX_SIZE] = {0};
    int c[MAX_SIZE] = {0};
    int ch = 0;
    int i=0, j=0, ra=0, rb=0, rc=0;
    printf("请输入集合A的数据：（已 -9999结束）\n");
    while(i < MAX_SIZE)
    {
        scanf("%d", &a[i]);
        if(a[i] == -9999)
        {
            break ;
        }
        i++;
    }
    printf("请输入集合B的数据：（已 -9999结束）\n");
    while(j < MAX_SIZE)
    {
        scanf("%d", &b[j]);
        if(b[j] == -9999)
        {
            break;
        }
        j++;
    }
    // 排序
    Bubble_sort(a, i);
    // 排序
    Bubble_sort(b, j);
    printf("开始移除重复数据\n");
    // 移除重复数据
    ra = RemoveRepeatData(a, i);
    // 移除重复数据
    rb = RemoveRepeatData(b, j);
    printf("A移除重复数据结果：\n");
    for(i=0; i<ra; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nB结果：\n");
    for(i=0; i<rb; i++)
    {
        printf("%d ", b[i]);
    }
    // 差集
    rc = differentSet(a, ra, b, rb, c);
    printf("\nA-B差集结果：\n");
    for(i=0; i<rc; i++)
    {
        printf("%d ", c[i]);
    }
    memset(c, 0, rc);
    // 交集
    rc = InsersectionSet(a, ra, b, rb, c);
    printf("\nA-B交集结果：\n");
    for(i=0; i<rc; i++)
    {
        printf("%d ", c[i]);
    }
    memset(c, 0, rc);
    // 并集
    rc = UnionSet(a, ra, b, rb, c);
    // 排序
    Bubble_sort(c, rc);
    //
    printf("\nA-B并集结果：\n");
    for(i=0; i<rc; i++)
    {
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}