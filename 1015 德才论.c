//#include <stdio.h>
//
//typedef struct {
//    int id;
//    int de, cai;
//    int total;
//} student;
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    printf("Hello, World!\n");
//
//    char flag1[4][250000];
//    int flag2[4] = { 0 };
//    student stu[100000];
//    int idNum;
//    int num, deScore, caiScore, high, low, count=0;
//
//    scanf("%d %d %d", &num, &low, &high);
//
//    for (int i=0; i<num; i++) {
//        scanf("%d", &idNum);
//        scanf("%d %d", &deScore, &caiScore);
//
//        if (deScore<low || caiScore<low) {
//            continue;
//        } else {
//            stu[count].id = idNum;
//            stu[count].de = deScore;
//            stu[count].cai = caiScore;
//            stu[count].total = deScore + caiScore;
//
//            if (deScore>=high && caiScore>=high) {
//                flag1[0][flag2[0]++] = count;
//            } else if (deScore>=high && caiScore>=low) {
//                flag1[1][flag2[1]++] = count;
//            } else if (deScore >= caiScore) {
//                flag1[2][flag2[2]++] = count;
//            } else {
//                flag1[3][flag2[3]++] = count;
//            }
//            count++;
//        }
//    }
//
//    printf("%d\n", count);
//    int temp = 0;
//    for (int i=0; i<4; i++) {
//        for (int j=1; j<flag2[i]; j++) {
//            for (int k=0; k<j; k++) {
//                if (stu[flag1[i][j]].total > stu[flag1[i][k]].total ) {
//                    temp = flag1[i][j];
//                    flag1[i][j] = flag1[i][k];
//                    flag1[i][k] = temp;
//                } else if (stu[flag1[i][j]].total == stu[flag1[i][k]].total) {
//                    if (stu[flag1[i][j]].de > stu[flag1[i][k]].de) {
//                        temp = flag1[i][j];
//                        flag1[i][j] = flag1[i][k];
//                        flag1[i][k] = temp;
//                    } else if (stu[flag1[i][j]].de == stu[flag1[i][k]].de && stu[flag1[i][j]].id<stu[flag1[i][k]].id) {
//                        temp = flag1[i][j];
//                        flag1[i][j] = flag1[i][k];
//                        flag1[i][k] = temp;
//                    }
//                }
//            }
//        }
//    }
//
//    for (int i=0; i<4; i++) {
//        for (int j=0; j<flag2[i]; j++) {
//            printf("%d %d %d\n", stu[flag1[i][j]].id, stu[flag1[i][j]].de, stu[flag1[i][j]].cai);
//        }
//    }
//
//    return 0;
//}
//

//自己的方法运行超时，不能用这种排序方法，借鉴一下别人的吧
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int iID;
    int iDE;
    int iCAI;
    int iSum;
    int iFlag;
} STUDENT;

int cmp(const void *a, const void *b)
{
    STUDENT *p=(STUDENT *)a;
    STUDENT *q=(STUDENT *)b;
    int flag=0;//返回值为正则交换位置，否则不变
    if(p->iFlag<q->iFlag)
    {
        flag=-1;
    }
    else if(p->iFlag>q->iFlag)
    {
        flag=1;
    }
    else
    {
        if(p->iSum>q->iSum)
        {
            flag=-1;
        }
        else if(p->iSum<q->iSum)
        {
            flag=1;
        }
        else
        {
            if(p->iDE>q->iDE)
            {
                flag=-1;
            }
            else if(p->iDE<q->iDE)
            {
                flag=1;
            }
            else
            {
                if(p->iID<q->iID)
                {
                    flag=-1;
                }
                else
                {
                    flag=1;
                }
            }
        }
    }
    return flag;
}

int main()
{
    int iNum=0,iLow=0,iHigh=0;
    //注意此处数组定义的问题，数组定义student[iNum]可以为变量但是它后面就不能初始化了Variable-sized object may not be initialized，适合在先输入数组长度，在读入数组时使用比如下面。不过要注意不能初始化的话s他里面的值不知道是多少的（就算是Xcode也不默认是1），不能使用要先写入。
    //而且constant int a = 9；在char s[a] = { 2 };这个倒是可以的。
    scanf("%d%d%d",&iNum,&iLow,&iHigh);
    int iCnt=0;
    STUDENT student[iNum];
    for(int i=0;i<iNum;i++)
    {
        scanf("%d%d%d",&student[iCnt].iID,&student[iCnt].iDE,&student[iCnt].iCAI);
        if(student[iCnt].iDE>=iLow&&student[iCnt].iCAI>=iLow)
        {
            student[iCnt].iSum=student[iCnt].iDE+student[iCnt].iCAI;
            if(student[iCnt].iDE>=iHigh&&student[iCnt].iCAI>=iHigh)
            {
                student[iCnt].iFlag=1;
            }
            else if(student[iCnt].iDE>=iHigh)
            {
                student[iCnt].iFlag=2;
            }
            else if(student[iCnt].iDE>=student[iCnt].iCAI)
            {
                student[iCnt].iFlag=3;
            }
            else
            {
                student[iCnt].iFlag=4;
            }
            iCnt++;
        }
    }
    //我的天，他就用了一个方法把数组都排列好了，厉害啊。
    qsort(student,iCnt,sizeof(student[0]),cmp);
    printf("%d\n",iCnt);
    for(int i=0;i<iCnt;i++)
    {
        printf("%08d %d %d",student[i].iID,student[i].iDE,student[i].iCAI);
        if(i!=iCnt-1)
        {
            printf("\n");
        }
    }
    return 0;
}

