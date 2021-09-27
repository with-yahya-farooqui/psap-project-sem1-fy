#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i,j;
int a1[30];
int a2[30];
int a3[30];
int a4[30];
int a5[30];
int a6[30];
float pc[30];
int rc[30];
int main()
{
    printf("\t  T9\n");
    printf("Welcome to SUNRISE ATTENDANCE DATABASE.\nOur database stores attendance of a class of 30 students with attendance of 6 days stored.\nIn the database present is represented by 1 and absent is represented by 0.\n");
    printf("Features available:\n1.Entry of attendance\n2.Full Class general stats.\n3.Defaulter list\n4.High flyer list\n5.Referral to attendance.\n");
    printf("\n\n\n\nATTENDANCE TABLE OF CLASS:\n******************\n");
    for(i=1;i<31;i++)
    {
        rc[i-1]=i;
        if(i<9)printf("%d   ",i);
        else printf("%d  ",i);
    }
    printf("\n");
    srand(time(0));
    for(i=0;i<30;i++) 
    {
        if(rand()%2==0) a1[i]=0;
        else a1[i]=1;
        printf("%d   ",a1[i]);
    }printf("\n");
    for(i=0;i<30;i++) 
    {
        if(rand()%2==0) a2[i]=0;
        else a2[i]=1;
        printf("%d   ",a2[i]);
    }printf("\n");
    for(i=0;i<30;i++) 
    {
        if(rand()%2==0) a3[i]=0;
        else a3[i]=1;
        printf("%d   ",a3[i]);
    }printf("\n");
    for(i=0;i<30;i++) 
    {
        if(rand()%2==0) a4[i]=0;
        else a4[i]=1;
        printf("%d   ",a4[i]);
    }printf("\n");
    for(i=0;i<30;i++) 
    {
        if(rand()%2==0) a5[i]=0;
        else a5[i]=1;
        printf("%d   ",a5[i]);
    }printf("\n");
    for(i=0;i<30;i++) 
    {
        if(rand()%2==0) a6[i]=0;
        else a6[i]=1;
        printf("%d   ",a6[i]);
    }printf("\n");
    float c=0;
    printf("\n\n\n\nPERCENT ATTENDANCE OF CLASS:\n******************\n");
    for(i=0;i<30;i++)
    {
        if(a1[i]==1) c++;
        if(a2[i]==1) c++;
        if(a3[i]==1) c++;
        if(a4[i]==1) c++;
        if(a5[i]==1) c++;
        if(a6[i]==1) c++;
        pc[i]=c/6.0*100;
        printf("RN:%d=%f\n",rc[i],pc[i]);c=0;
    }
   
    float pc1[30];int rc1[30];float avg=0;
    for(i=0;i<30;i++)
    {
        pc1[i]=pc[i];rc1[i]=rc[i];avg+=pc[i];
    }
    avg/=30;
    for(i=0;i<29;i++)
    {
        for(j=0;j<29-i;j++)
        {
            if(pc1[j]>pc1[j+1])
            {
                pc1[j]+=pc1[j+1];
                pc1[j+1]=pc1[j]-pc1[j+1];
                pc1[j]-=pc1[j+1];
                rc1[j]+=rc1[j+1];
                rc1[j+1]=rc1[j]-rc1[j+1];
                rc1[j]-=rc1[j+1];
            }//ascending
        }
    }
    printf("\n\n\nDefaulters list:\n***********\n");
    for(i=0;i<5;i++)
       printf("RN:%d=%f\n",rc1[i],pc1[i]);
     printf("\n\n\nHighflyers list:\n***********\n");
    for(i=29;i>=25;i--)
       printf("RN:%d=%f\n",rc1[i],pc1[i]);
     printf("\n\n\nFull class general Statistics:\n************\n");
     printf("CLASS AVERAGE ATTENDANCE:%f\n",avg);
     printf("CLASS MAXIMUM ATTENDANCE:%f\n",pc1[29]);
     printf("CLASS MINIMUM ATTENDANCE:%f\n",pc1[0]);
     printf("CLASS  MEDIAN ATTENDANCE:%f\n",(pc1[14]+pc1[15])/2);
     printf("CLASS   RANGE ATTENDANCE:%f\n",pc1[29]-pc1[0]);
     int rno,dno;
         printf("\n\n\n\nEnter roll number and day number(1-6) to check attendance.\n");
         scanf("%d%d",&rno,&dno);
         if(rno>30||rno<1||dno>6||dno<1) 
         {
             printf("Wrong input.");return 0;
         }
         else
         {
             if(dno==1&&a1[rno-1]==0)printf("Roll Number %d was absent on day %d",rno,dno);
             else if(dno==2&&a2[rno-1]==0)printf("Roll Number %d was absent on day %d",rno,dno);
             else if(dno==3&&a3[rno-1]==0)printf("Roll Number %d was absent on day %d",rno,dno);
             else if(dno==4&&a4[rno-1]==0)printf("Roll Number %d was absent on day %d",rno,dno);
             else if(dno==5&&a5[rno-1]==0)printf("Roll Number %d was absent on day %d",rno,dno);
             else if(dno==6&&a6[rno-1]==0)printf("Roll Number %d was absent on day %d",rno,dno);
             else if(dno==1&&a1[rno-1]==1)printf("Roll Number %d was present on day %d",rno,dno);
             else if(dno==2&&a2[rno-1]==1)printf("Roll Number %d was present on day %d",rno,dno);
             else if(dno==3&&a3[rno-1]==1)printf("Roll Number %d was present on day %d",rno,dno);
             else if(dno==4&&a4[rno-1]==1)printf("Roll Number %d was present on day %d",rno,dno);
             else if(dno==5&&a5[rno-1]==1)printf("Roll Number %d was present on day %d",rno,dno);
             else if(dno==6&&a6[rno-1]==1)printf("Roll Number %d was present on day %d",rno,dno);
          }
}
