#include<stdio.h>
#include<conio.h>

char stuID[20];
int dd,mm,yy;
char name[50];
char mobn[20];
float marks;

void write()
{
   FILE *fp;
   char stID[20];
   int d,m,y;
   char nam[50];
   char mob[20];
   float mark;

   printf("\nEnter Student ID (Don't Use Space): ");
   scanf("%s",stID);
   printf("\nEnter Date of Birth (dd/mm/yyyy): ");
   scanf("%d/%d/%d",&d,&m,&y);
   check(d,m,y);
   printf("\nEnter Name of the Student (Name_Subtitle): ");
   scanf("%s",nam);
   printf("\nEnter Mobile Number: ");
   scanf("%s",mob);
   printf("\nEnter Marks of the Student: ");
   scanf("%f",&mark);
   fp=fopen("record.txt","a");
   fprintf(fp,"\n%s %d/%d/%d %s %s %f",stID,d,m,y,nam,mob,mark);
   printf("\n      Record Saved Successfully !!!");
   fclose(fp);
}

void displayDOB(int da,int mo,int yr)
{
    FILE *fp;
    fp=fopen("record.txt","r");
    while(fscanf(fp,"%s %d/%d/%d %s %s %f",stuID,&dd,&mm,&yy,name,mobn,&marks)!=EOF)
    {

        if(dd==da && mm==mo && yy==yr)
        {
            printf("\n\nStudent ID : %s",stuID);
            printf("\nDate of Birth: %d/%d/%d",dd,mm,yy);
            printf("\nName of the Student: %s",name);
            printf("\nMobile Number: %s",mobn);
            printf("\nMarks of the Student: %f",marks);
           /* printf("\n %s || %d/%d/%d || %s || %s || %f",stuID,dd,mm,yy,name,mobn,marks);*/
        }
    }
    fclose(fp);
}
void displayID(char id[])
{

    FILE *fp;
    int res;
    fp=fopen("record.txt","r");
    while(fscanf(fp,"%s %d/%d/%d %s %s %f",stuID,&dd,&mm,&yy,name,mobn,&marks)!=EOF)
    {
        res=strcmp(stuID,id);
        if(res==0)
        {
            printf("\n\nStudent ID : %s",stuID);
            printf("\nDate of Birth: %d/%d/%d",dd,mm,yy);
            printf("\nName of the Student: %s",name);
            printf("\nMobile Number: %s",mobn);
            printf("\nMarks of the Student: %f",marks);
           /* printf("\n %s || %d/%d/%d || %s || %s || %f",stuID,dd,mm,yy,name,mobn,marks);*/
        }
    }
    fclose(fp);
}
int check(int d,int m,int y)
{
        if(d>0 && d<=31 && m>0 && m<=12 && y<=2017)
    {
        if(m==2)
        {
            if(y%4==0 || y%400==0)
            {
                if(d<=29)
                return;
                else
                {
                    printf("\n\t\t INVALID DATE..!!\n \t\t PLEASE ReENTER\n");
                    main();
                }
            }
            else if(d<=28)
            return;
            else
            {
                 printf("\n\t\t INVALID DATE..!!\n \t\t PLEASE ReENTER\n");
                 main();
            }

        }
        else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
        {
            if(d<=31)
                return;
            else
                {
                 printf("\n\t\t INVALID DATE..!!\n \t\t PLEASE ReENTER\n");
                 main();
                }
        }
        else if(m==4 || m==6 || m==9 || m==11)
        {
            if(d<=30)
                return;
            else
                {
                 printf("\n\t\t INVALID DATE..!!\n \t\t PLEASE ReENTER\n");
                 main();
                }
        }

  }
    else
   {
    printf("\n\t\t INVALID DATE..!!\n \t\t PLEASE ReENTER\n");
    main();
   }
}

int main()
{
    int ch,da,mo,yr;
    char id[20];
    do
    {
    printf("\n\n");
    printf("\t* * * STUDENT DATABASE * * *\n");
    printf("\nPress 1 to CREATE ENTRY FOR NEW STUDENT");
    printf("\nPress 2 to DISPLAY ALL INFORMATION ON SPECIFIC DATE OF BIRTH ");
    printf("\nPress 3 to DISPLAY ALL INFORMATION ON SPECIFIC STUDENT ID ");
    printf("\nPress 4 to EXIT");
        printf("\nEnter Choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            write();
            break;
        case 2:
            printf("\nENTER DATE OF BIRTH (dd/mm/yyyy): ");
            scanf("%d/%d/%d",&da,&mo,&yr);
            check(da,mo,yr);
            displayDOB(da,mo,yr);
            break;
        case 3:
            printf("\nENTER STUDENT ID: ");
            scanf("%s",id);
            displayID(id);
            break;
        case 4:
            exit(0);
        default:
            printf("\nINVALID SELECTION");
        }
        getch();
    }
    while(ch!=0);
    return 0;
}
