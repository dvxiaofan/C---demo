//
//  main.c
//  我的通讯录
//
//  Created by 张张张小烦 on 16/1/13.
//  Copyright © 2016年 张张张小烦. All rights reserved.
//

#include <stdio.h>
#include <string.h>//要用到数组对比
typedef struct person//定义一个保存信息的结构：联系人
{
    char name[20];//里面包含一个保存名字的数组，每个汉字占3个字节，最多6个字
    char tel[12];//电话号码数组，最多11位
}Person;//用typedef简化结构名称，使用方便
void init();//初始化
void menu();
void add();//增加
void deleted();//删除
void find();//查找
void update();//修改
void show();//显示
void write_file();
#define MAX 1000//定义一个宏，表示通讯录里最多保存多少人
Person person[MAX];//所有联系人
int n;//总人数
int main(int argc, const char * argv[])
{
    printf("欢迎使用我的通讯录！\n\n");//显示提示
    //write_file();
    init();//初始化，把磁盘上的数据读到内存中来
    menu();//菜单
    return 0;
}
void init()//初始化文件函数定义
{
    int count=0;//定义一个联系人个数
    FILE *fp=NULL;//初始化文件
    fp=fopen("telbook.data", "rb");//第一步，打开文件读，
    if (fp==NULL)//如果没有这个文件，需要创建一个
    {
        fp=fopen("telbook.data", "wb");//写入一个文件
        fwrite(&count, sizeof(count), 1, fp);//写入文件中联系人个数
        fclose(fp);//相应的关闭文件
        return;
    }
    else//如果有文件，就打开读取内容
    {
        fp=fopen("telbook.data", "rb");
        fread(&n, sizeof(int), 1, fp);//读出文件中联系人个数
        for (int i=0; i<n; i++)//循环读取
        {
            fread(&person[i], sizeof(Person), 1, fp);//获得联系人信息
        }
    }
    fclose(fp);//关闭文件
}
void menu()
{
    while (1)
    {
        printf("1、增加一个联系人!\n");
        printf("2、删除一个联系人!\n");
        printf("3、查找一个联系人!\n");
        printf("4、修改一个联系人!\n");
        printf("5、显示所有联系人!\n");
        printf("6、退出!\n\n");
        char ch[2];//定义一个输入的字符串数组，组多两个字符
        ch[1]='\0';//令第二个字符位结尾
        printf("请输入您想进行的操作编号：");
        scanf("%s",ch);
        if (strcmp(ch, "1")==0)//根据输入的内容进行相应的函数调用
        {
            add();
        }
        else if (strcmp(ch, "2")==0)
        {
            deleted();
        }
        else if (strcmp(ch, "3")==0)
        {
            find();
        }
        else if (strcmp(ch, "4")==0)
        {
            update();
        }
        else if (strcmp(ch, "5")==0)
        {
            show();
        }
        else if (strcmp(ch, "6")==0)
        {
            break;
        }
        else
        {
            printf("对不起，输入无效！\n");
        }
    }
}
void write_file()//写入文件的函数
{
    FILE *fp;//初始化文件
    fp=fopen("telbook.data", "wb");//打开文件写入
    fwrite(&n, sizeof(int), 1, fp);//写的内容
    for (int i=0; i<n; i++)
    {
        fwrite(&person[i], sizeof(Person), 1, fp);//写入结构中的内容
    }
    fclose(fp);//关闭文件
}
void add()//函数声明
{
    printf("请输入添加联系人的姓名:");
    scanf("%s",person[n].name);
    printf("请输入添加联系人的手机号:");
    scanf("%s",person[n].tel);
    //对数据有效性进行判断
    
    n++;//联系人数量累加
    //同步到磁盘中
    write_file();//调用增加函数
    printf("\n联系人添加成功!\n\n");
}
void deleted()
{
    //询问要删除的联系人
    int nn;
    printf("\n请输入您想删除的人编号：");
    scanf("%d",&nn);
    //输入数据验证
    if (nn<1||nn>n)
    {
        printf("\n对不起，输入无效！\n");
        return;
    }
    //询问是否确认删除
    
    //从内存中删除数据
    else if (nn==0)//第一个
    {
        for (int i=1; i<n; i++)
        {
            person[i-1]=person[i];
        }
        n--;
    }
    else if (nn==n)//最后一个
    {
        n--;
    }
    else//中间一个
    {
        for (int i=nn; i<n; i++)
        {
            person[i-1]=person[i];
        }
        n--;
    }
    //同步到磁盘中
    write_file();
}
void find()
{
    //获得要查找联系人的姓名
    char ch[20];
    printf("请输入您要查找联系人的姓名：");
    scanf("%s",ch);
    //去内存中查找
    int bz=0;
    for (int i=0; i<n; i++)
    {
        if (strcmp(person[i].name, ch)==0)
        {
            printf("\n%s 的电话号码是 %s\n",person[i].name,person[i].tel);
            bz=1;
        }
    }
    if (bz==0)
    {
        printf("\n对不起，查无此人\n");
    }
    //显示相关信息
}
void update()
{
    //获得要修改联系人的编号
    int nn;
    printf("请输入您想修改联系人的编号：");
    scanf("%d",&nn);
    //对输入数据进行有效性验证
    if (nn<1||nn>n)
    {
        printf("\n对不起，输入无效！\n");
        return;
    }
    //到内存中去修改
    char ch[20];
    char tel[12];
    printf("请输入修改后联系人名字:");
    scanf("%s",ch);
    ch[19]='\0';
    printf("请输入修改后联系人电话：");
    scanf("%s",tel);
    tel[11]='\0';
    strcpy(person[nn-1].name, ch);
    strcpy(person[nn-1].tel, tel);
    printf("\n信息修改成功！\n");
    //同步到磁盘中
}
void show()//函数声明
{
    if (n==0)
    {
        printf("sorry，目前通讯录里暂时空无一人！\n");
    }
    else
    {
        printf("编号\t姓名\t手机号码\n");
        for (int i=0; i<n; i++)
        {
            printf("%02d\t%s\t%s\n",i+1,person[i].name,person[i].tel);
        }
    }
}
