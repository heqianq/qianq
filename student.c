#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"

#define numberOfStudents 100
/*分配空间*/
STU *allocStudentRecords(int number)
{
    STU *stu = NULL;
    int size = number * sizeof(STU);
    stu = malloc(size);
    if (stu == NULL){
    
        perror("malloc");
        return NULL;

    }
//    memset(stu,0,size);
//      numberOfStudents = number;
    return stu;
}
/*打印每个学生的信息*/
static void printStudent(STU *stu,int index)
{
    printf("Student's Name is :%s\n",stu[index].name);
    printf("Student's Age is :%d\n",stu[index].age);
    printf("Student's studyID is :%d\n",stu[index].studyID);
    printf("=======================================\n");
}
/*打印所有学生的信息*/
void printStudents(STU *stu)
{
    for(int i = 0;i < numberOfStudents; i++){
    
        if(stu[i].useFlag){
        
            printfStudent(stu,i);
        }
    }
}
/*检查学生学号是否冲突*/
static int checkStudyID(STU *stu,int studyID)
{
    for(int i = 0;i < numberOfStudents; i++){
    
        if(studyID == stu[i].studyID && stu[i].useFlag == 1){
        
            return -1;
        }
    }
    return 0;

    
}

/*获取空闲位置的索引*/
static int getFreePosition(STU *stu)
{
    for(int i = 0;i < numberOfStudents; i++){
    
        if(stu[i].useFlag == 0)
        {
            return i;
        }
    }
    return -1;
}
/*添加学生信息 */

int addStudent(STU *stu, char *name,int age,int studyID )
{
    int index = -1;
    if (checkStudyID(stu,studyID) < 0){
    
        fprintf(stderr,"student <%d> already exit!\n",studyID);
        return -1;
    }
    index = getFreePosition(stu);
    if (index < 0){
    
        fprintf(stderr,"no free position!\n");
        return -1;

        strncpy(stu[index].name,name,NAMELEN-1);/*名字的赋值*/
        stu[index].age = age;
        stu[index].studyID = studyID;
        stu[index].useFlage = 1;
        printf("Add sucessfully!\n");
        return 0;

    }


}

int delStudent(STU *stu,int studyID)
{
    for(int i = 0;i < numberOfStudents; i++){
    
        if (stu[i].studyID == studyID && stu[i].useFlag)
        {
            stu[i].useFlag = 0;
            printf("delete successfully!\n");
            return 0;
        }
    }
        fprintf(stderr,"student %d not exit!\n",studyID);
        return -1;
    }

    
int searchStudent(STU *stu,int studyID)
{
    for(int i = 0;i < numberOfStudents; i++){
        
        if (stu[i].studyID == studyID && stu[i].useFlag)
        {
            printStudent(stu,i);
            return 0;
        }
    }
        fprintf(stderr,"student %d not exit!\n",studyID);
        return -1;

}
void deallocStudentRecords(STU *stu)
{
    free(stu);
}
