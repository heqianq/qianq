#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "student.h"

#define BUFSIZE  32
#define STUNUM   32

static long getInput(void)
{
    char buf[BUFSIZE] = {0};
    long result = -1;

    fgets(buf,BUFSIZE,stdin);
    result = strtol(buf,NULL,0);
    if ((result == 0 && errno == EINVAL) || (error == ERANGE)){
    
        result = -1;
        errno = 0;
    }
    return result;
}

static int getStudyID(void)
{
    int studyID = -1;
_InputStudyID:
    fprintf(stdout,"please input student's studyID:\n");
    studyID = (int)getInput();
    if (studyID < MINSTUDYID || studyID > MAXSTUDYID ){
    
        fprintf(stderr,"invalid input!(studyID must in [20140001-20149999])\n");
        goto _InputStudyID;
    }
    return studyID;
}



int main(void)
{

    long cmd = -1;
    char stuName[NAMELEN] = {0};
    int stuAge = -1;
    int studyID = -1;
    STU *stu = NULL;

    stu = allocStudentRecords(STUNUM);
    if (NULL == stu){
    
        goto _Fail;
    }
    while(1){
    
        fprintf(stdout,"please input command number:\n 0 --List\t1--Add\t2--Delete\t3--Search\t4--Quit\n");
cmd = getInput();
fpurge(stdin);
if (cmd == -1 || cmd > kQuitCMD || cmd < kListStudents){

    fprintf(stderr,"Invalid Command!\n");
    continue;
}
switch (cmd) {

    case kListStudent:
        printfStudents(stu);
        break;
    case kAddStudent:
        fprintf(stdout,"please input student's name:\n");
        fgets(stuName,NAMELEN,stdin);
        stuName[strlen(stuName)-1] = '\0';

_InputAge:
        fprintf(stdout,"please input student's age:\n");
        stuAge = (int)getInput();
        if (stuAge < MINAGE || stuAge > MAXAGE)
        {
            fprintf(stderr,"Invalid input!(Age must in[4-100])\n");
            goto _InputAge;
        }
        studyID = getStudyID();
        addStudent(stu,stuName,stuAge,studyID);
        break;
    case kDelStudent:
        studyID = getStudyID();
        delStudents(stu,studyID);
        break;
    case kSearchStudent:
        studyID = getStudyID();
        searchStudent(stu,StudyID);
        break;
    case kQuitCMD:
        goto _Exit;
        break;
    default:
        fprintf(stderr,"Unkown command!\n");
        break;
}
      }
_Fali:
    exit(1);
_Exit:
    deallocStudentRecords(stu);
    return 0;

}
