//
//  main.c
//  输入数字按顺序排列
//
//  Created by 张张张小烦 on 16/1/11.
//  Copyright © 2016年 张张张小烦. All rights reserved.
//把输入数字按大小顺序排列

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int num[10];//定义一个整型数组，把输入的数字保存到相应单元上
    //int min;
    for (int i=0; i<10; i++)//用for循环输入数字
    {
        printf("请输入第%d个数：",i+1);
        scanf("%d",&num[i]);//输入数字，赋值给整形数组
    }
    for (int i=0; i<9; i++)//产生一个0-8位置
    {
        for (int j=i+1; j<10; j++)//产生前面位置后面的位置
        {
            if (num[i]>num[j])//如果后面的数字小，就把后面的数字放前面
            {
                int t=num[i];//定义一个中间转换变量
                num[i]=num[j];//开始转换
                num[j]=t;//开始转换
            }
        }
    }
    for (int i=0; i<10; i++)//用for循环输出转换后的数字
    {
        printf("%d\t",num[i]);//输出转换后的数组数字
    }
    
    printf("\n");//换行显示，整洁
    return 0;
}
