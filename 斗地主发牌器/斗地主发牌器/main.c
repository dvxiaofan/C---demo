//
//  main.c
//  斗地主发牌器
//
//  Created by 张张张小烦 on 16/1/11.
//  Copyright © 2016年 张张张小烦. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>//随机函数头问件
#include <time.h>//初始化函数头文件
int cards[54];//定义全局变量，任何函数都可以使用
void init();//声明函数
void mix();//声明函数
void show();//声明函数
int main(int argc, const char * argv[])
{
    srandom((unsigned)time(NULL));//初始化随机函数
    //初始化
    init();//调用函数
    //混牌
    mix();//调用函数
    //显示
    show();//调用函数
    printf("\n");//最后换行显示
    
    return 0;
}


void init()//定义初始化函数
{
    for (int i=0; i<54; i++)
    {
        cards[i]=i;
    }
}
void mix()//定义混合函数
{
    for (int i=0; i<100; i++)//混合100次
    {
        int a=random()%54;
        int b=random()%54;
        int t=cards[a];
        cards[a]=cards[b];
        cards[b]=t;
    }
}
void show()//定义显示函数
{
    char styles[4][8]={"♠️","♥️","♣️","♦️"};
    char number[13][3]={"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    for (int i=0; i<54; i++)
    {
        if (cards[i]==52)
        {
            printf("小王 ");
        }
        else if (cards[i]==53)
        {
            printf("大王 ");
        }
        else
        {
            printf("%s%s ",styles[cards[i]/13],number[cards[i]%13]);
        }
        if ((i+1)%17==0)//够17张换行
        {
            printf("\n");
        }
    }
}
