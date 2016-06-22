//
//  main.c
//  统计数组偶数和个数
//
//  Created by 张张张小烦 on 16/1/15.
//  Copyright © 2016年 张张张小烦. All rights reserved.
// 统计数组中的偶数个数

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /*
    int a[10],*p1,**p2,i,n=0;
    printf("请输入数值 :\n");
    for (i=0; i<10; i++)
    {
        scanf("%d",&a[i]);
    }
    p1=a;
    p2=&p1;
    printf("其中的偶数是:");
    for (i=0; i<10; i++)
    {
        if (*(*p2+i)%2==0)
        {
            printf("%5d",*(*p2+i));
            n++;
        }
    }
    printf("\n");
    printf("偶数的个数是:%d\n",n);
     */
    int a[10],*p1,**p2,n=0;
    printf("please input :\n");
    for (p1=a; p1-a<10; p1++)
    {
        p2=&p1;
        scanf("%d",*p2);
    }
    //printf("the array is:");
    for (p1=a; p1-a<10; p1++)
    {
        p2=&p1;
        if (**p2>0)
        {
            //printf("%d",**p2);
            n++;
        }
    }
    printf("\n");
    printf("the number is:%d\n",n);
    
    return 0;
}
