//
//  main.c
//  指针做函数参数
//
//  Created by 张张张小烦 on 16/1/15.
//  Copyright © 2016年 张张张小烦. All rights reserved.
// 调用自定义函数交换两个变量的值

#include <stdio.h>
void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int main(int argc, const char * argv[]) {
    
    int x,y;
    int *p_x,*p_y;
    printf("please input two number:\n");
    scanf("%d",&x);
    scanf("%d",&y);
    p_x=&x;
    p_y=&y;
    swap(p_x,p_y);
    printf("x=%d\n",x);
    printf("y=%d\n",y);
    return 0;
}
