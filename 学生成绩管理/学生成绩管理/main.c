//
//  main.c
//  学生成绩管理
//
//  Created by 张张张小烦 on 16/1/12.
//  Copyright © 2016年 张张张小烦. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define STUDENTS 100//定义宏
#define ITEMS 10//同上
void input(int *n,int *k,char name[][20],char itemname[][10],int score[STUDENTS][ITEMS]);//指针函数声明
void show(int *n,int *k,char name[][20],char itemname[][10],int score[STUDENTS][ITEMS]);//指针函数声明
void sort(int *n,int *k,char name[STUDENTS][20],int score[STUDENTS][ITEMS]);
int main(int argc, const char * argv[])
{
    int n;//班级总人数
    int k;//班级总科目
    char name[STUDENTS][20];//保存名字的二维数组
    char itemname[ITEMS][10];//保存科目名字的二维数组
    int score[STUDENTS][ITEMS];//保存分数的整型二维数组
    input(&n,&k,name,itemname,score);//调用输入函数
    show(&n,&k,name,itemname,score);//调用输出函数
    sort(&n,&k,name,score);
    show(&n,&k,name,itemname,score);
    return 0;
}
//输入函数
void input(int *n,int *k,char name[][20],char itemname[][10],int score[STUDENTS][ITEMS])//定义指针式输入函数
{
    printf("请输入班级人数：");//获取总人数
    scanf("%d",n);
    printf("请输入科目数：");//获取科目数
    scanf("%d",k);
    for (int i=0; i<*k; i++)//循环获得科目名字
    {
        printf("请输入第%d个科目名字：",i+1);
        scanf("%s",itemname[i]);
    }
    for (int i=0; i<*n; i++)//循环获得同学名字
    {
        printf("请输入第%d位同学的名字：",i+1);
        scanf("%s",name[i]);
        score[i][*k]=0;//定义总分为零
        for (int j=0; j<*k; j++)//循环获得每名同学每科成绩
        {
            printf("请输入%s同学%s科目的成绩：",name[i],itemname[j]);
            scanf("%d",&score[i][j]);
            score[i][*k]+=score[i][j];//总分累加而出
        }
    }
}
//输出函数
void show(int *n,int *k,char name[][20],char itemname[][10],int score[STUDENTS][ITEMS])//定义指针式输出函数
{
    printf("姓名\t");//输出姓名显示
    for (int i=0; i<*k; i++)//循环输出科目名字
    {
        printf("%s\t",itemname[i]);
    }
    printf("总分\n");//输出总分提示
    for (int i=0; i<*n; i++)//循环输出每个名字
    {
        printf("%s\t",name[i]);
        for (int j=0; j<=*k; j++)//内循环输出每科成绩
        {
            printf("%d\t",score[i][j]);
        }
        printf("\n");
    }
}
//排序函数
void sort(int *n,int *k,char name[STUDENTS][20],int score[STUDENTS][ITEMS])
{
    char temp[40];//定义一个临时数组
    for (int i=0; i<*n-1; i++)//比较排名，跟后面的比
    {
        for (int j=i+1; j<*n; j++)//后面的人
        {
            if (score[i][*k]<score[j][*k])//判断谁的总分高
            {
                int t=score[i][*k];//进行总分调换
                score[i][*k]=score[j][*k];
                score[j][*k]=t;
                
                strcpy(temp, name[i]);//姓名调换
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
                
                for (int m=0; m<*k; m++)//各科分数调换
                {
                    int t=score[i][m];
                    score[i][m]=score[j][m];
                    score[j][m]=t;
                }
            }
        }
    }
}
