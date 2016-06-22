//
//  main.c
//  彩票21选5
//
//  Created by 张张张小烦 on 16/1/11.
//  Copyright © 2016年 张张张小烦. All rights reserved.
//
//这个是彩票21选5，一共选取6注的项目

#include <stdio.h>
#include <stdlib.h>//用随机函数，要包含这个头文件
#include <time.h>//要用到时间函数，要包含这个头文件

int main(int argc, const char * argv[])
{
    srandom((unsigned)time(0));//先初始化随机函数，并且强制格式转换
    int num[5];//定义一个数组，用来保存每注里的数字
    int j,k;//定义两个循环变量
    for (int i=0; i<6; i++)//总共要产生几注，用for循环
    {
        for (j=0; j<5; j++)//每一注里面产生几个数字，用for循环
        {
            num[j]=random()%21+1;//先产生一个随机数，用的是求余数公式
            for (k=0; k<j; k++)//再产生这注之前的数字
            {
                if (num[j]==num[k])//比较之前有没有这个数字，如果有
                {
                    break;//结束循环
                }
            }
            if (j==k)//如果之前没有这个数字
            {
                printf("%d\t",num[j]);//就把没有的数字输出出来
            }
            else
            {
                j--;//否则就取消这次循环，再重新做一次循环
            }
        }
        printf("\n");//换行
    }
    return 0;
}
