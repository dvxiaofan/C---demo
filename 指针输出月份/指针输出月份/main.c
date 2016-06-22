//
//  main.c
//  指针输出月份
//
//  Created by 张张张小烦 on 16/1/15.
//  Copyright © 2016年 张张张小烦. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i;
    char **p;
    char *month[]=
    {
        "一月January",
        "二月February",
        "三月March",
        "四月April",
        "五月May",
        "六月June",
        "七月July",
        "八月August",
        "九月September",
        "十月October",
        "十一月November",
        "十二月December"
    };
    for (i=0; i<12; i++)
    {
        p=month+i;
        printf("%s\n",*p);
    }

    return 0;
}
