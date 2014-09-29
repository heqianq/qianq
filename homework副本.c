#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN sizeof(struct student)


struct student
{
int num[20];
char name[20];
char sex[5];
float score[20];
}stu[100];
/*输入学生信息*/

void put(void)
{
int i;
char n;
for(i = 0;i < 100; i++)
{
printf("please enter student's messsage:\n");
printf("num:");
scanf("%d",stu[i].num);
printf("name:");
scanf("%s",stu[i].name);
printf("sex:");
scanf("%s",stu[i].sex);
printf("score:");
scanf("%f",stu[i].score);

printf("Are you go no(y/n): \n");
scanf("%c", &n);
if(getchar() == 'n')
{
    break;
}

}
}

/*查询学生信息*/

void query(void)
{
    int number,i;
    char n;
    printf("please input query number: ");
    scanf("%d",&number);
for(i = 0;i <100;i++)
{
if(number == stu[i].num)
{
 printf("number:%d name:%s sex:%s score:%f\n",stu[i].num,stu[i].name,stu[i].sex,stu[i].score);
}

printf("Are you go no(y/n):\n ");
scanf("%c",&n);
if(n == 'n')
    break;
}

}
/*添加学生信息*/

void add(void)
{
 char n;
 int number,a,b,c;
struct student *p;
p = (struct student *) malloc (LEN);
for(p = stu;p < stu + 100; p++)
{
 printf("please input student's message: ");
 printf("please enter the number:");
    scanf("%d",&number);
 printf("please enter the name:");
    scanf("%d",&a);
 printf("please enter the  sex:");
    scanf("%d",&b);
 printf("please enter the score:");
    scanf("%d",&c);
//scanf("%d %s %s %f",p->num,p->name,p->sex,p->score);

 printf("Are you go no(y/n):\n ");
    scanf("%c",&n);
       if(n == 'n')
       {
          break;
       }
}

}


/* 删除学生信息*/
 
void del(void)
{
int i;
char n;
char id[10];
printf("please enter the delete number:");
scanf("%s",&id);
if (id == -1)
{
printf("error!");
}

for(i=0;i<100;i++)
{
if(id == stu[i].num)
{
    stu[i] = stu[i+1];
}

printf("Are you go no(y/n):\n ");
scanf("%c",&n);
if(n == 'n')
{
    break;
}

}
}


/*修改学生信息*/

void change(void)
{
 int i,number,a,b,c;
 char n;
 printf("please enter change bunber:");
scanf("%d",&number);
if(number == -1)
    printf("error");
for(i = 0;i < 100;i++)
{
if (number = stu[i].num)
{
printf("please enter the new number:");
scanf("%d",&number);
printf("please enter the new name:");
scanf("%d",&a);
printf("please enter the new sex:");
scanf("%d",&b);
printf("please enter the new score:");
scanf("%d",&c);
}

printf("Are you go no(y/n):\n ");
scanf("%c",&n);
if(n == 'n')
{
    break;
}

}

}




int main(void)
{
int choice;
 A:while(1)
{
printf("欢迎来到学生管理系统!\n");
printf("1---输入学生信息");
printf("2---查询学生信息");
printf("3---修改学生信息");
printf("4---增加学生信息");
printf("5---删除学生信息");
printf("0---退出");
printf("please enter your choice(0,5):");
scanf("%d",&choice);
if (choice < 0 || choice > 5)
{
goto A;
}
switch(choice)
{
    case(0):
        return 0;
        break;
     case(1):
        put();
        break;
     case(2):
        query();
        break;
     case(3):
        change();
        break;
      case(4):
        add();
        break;
      case(5):
        del();
        break;
}
return 0;



}










}
