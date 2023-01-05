#ifndef NEWPROJECT_MENU_H
#define NEWPROJECT_MENU_H


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
void movie_names(void);
void buy_ticket(void);
void old_trans(void);
void seatplan(int n);
int n=1;


void menu(void)
{
int num;
do {
    
printf("\n\n");
printf("                \n\n\n\t\t====================================================WELCOME TO CINEPLEX====================================================== ");
printf("\n\n\t\t\t\t\t\t===============================================================");
printf("\n\n\t\t\t\t\t\t||              CHOICE<1>: MOVIE NAMES                       ||");
printf("\n\n\t\t\t\t\t\t||              CHOICE<2>: BUY TICKET                        ||");
printf("\n\n\t\t\t\t\t\t||              CHOICE<3>: VIEW ALL TRANSACTION              ||");
printf("\n\n\t\t\t\t\t\t||              CHOICE<4>: EXIT                              ||");
printf("\n\n\t\t\t\t\t\t===============================================================\n");
printf("\n\nENTER YOUR CHOICE >");
scanf("%d", &num);
system("clear");


switch (num) {
case 1:
movie_names();
break;
case 2:
buy_ticket();
break;
case 3:
old_trans();
break;
case 4:
splash3();
break;
default:
printf("PLEASE ENTER YOUR CHOICE CAREFULLY");
break;

}

} while (num != 4);
}
void movie_names(void)
{
    system("color 30");
    char ch;

    FILE *movi;
    movi = fopen("movie_name1.txt","r");

    if(movi == NULL)
    {
        printf("File Does Not Exist!!!");
        exit(1);
    }
    else
    {
        system("clear");
        printf("\n\t\t\t\t\t\t\t\t\t !!!NOW PLAYING!!!\n\t\t\t\t\t\t\t\t\t<<<<<MOVIE LIST>>>>>\n\n\n");
        while(!feof(movi))
        {
            ch=fgetc(movi);
            printf("%c",ch);
        }
    }
    fclose(movi);
}


void buy_ticket(void)
{
    int count = 0;
    char ch;
    int i,j;

    char movie_num[20];
    FILE *movi;
    FILE *fp;
    int seat[10];
    int total_amount;
    typedef struct 
{
    char serial_no[10];
    char name[20];
    char date[10];
    char time[10];
    int cost;
}booking;
booking b[100];

    movi = fopen("movie_name1.txt","r");

    if(movi == NULL)
    {
        printf("File Does Not Exist!!!");
        exit(1);
    }
    else
    {
        system("clear");
        while(!feof(movi))
        {
            ch=fgetc(movi);
            printf("%c",ch);
        }
    }
    fclose(movi);

    printf("\n\n\n Please Choose Your Desired Movie \n\n Enter The Movie Code :>");
    scanf("%s",movie_num);
    
    sleep(1);
    system("clear");

    movi = fopen("movie_name1.txt","r");

    if(movi == NULL)
    {
        printf("File Does Not Exist!!!");
        exit(1);
    }

    else
    {
        while(!feof(movi))
        {
            fscanf(movi,"%s %s %s %s %d",b[count].serial_no,b[count].name,b[count].date,b[count].time,&b[count].cost);
            
            if(strcmp(b[count].serial_no,movie_num)==0)
            {
                printf("Movie Found\n");
                printf("\n\t\tMovie Serial Number  :> %s",b[count].serial_no);
                printf("\n\t\tMovie Name           :> %s",b[count].name);
                printf("\n\t\tDate                 :> %s",b[count].date);
                printf("\n\t\tTime                 :> %s",b[count].time);
                printf("\n\t\tTicket Price         :> %dTaka",b[count].cost);
                break;
            }
            count++;
        }
    }
    
    char name[20];
    long long int mblnum;
    int total_ticket;
    printf("\n Fill Up The Form :");
    printf("\n Enter Your Name  :");
    scanf("%s",name);
    printf("\n Enter Your Mobile Number :");
    scanf("%lld",&mblnum);
    start:
    printf("\n Total Number of Tickets :");
    scanf("%d",&total_ticket);
    if(total_ticket>=6)
    {
        printf("You can't book %d Tickets\n",total_ticket);
        printf("Please Book Less Than 7 Tickets\n");
        goto start;
    }
    system("clear");
    printf("\n\t\t\t\t\t\t\t            SCREEN\t\t\n\n\n");
    if(total_ticket<=5)
    {
        seatplan(n);
    }
    movi=fopen("avtSeat1.txt","r");
    if(movi == NULL)
    {
        printf("File Not Found");
        exit(1);
    }
    else
    {
        printf ("\n\nThese seats are booked for %s Movie->",b[count]. name);
        while( ( ch = fgetc(movi) ) != EOF )
            printf("%c",ch);
    }
    fclose(movi);
    
    printf ("\n\n Please choose other seats");
    for(i=1;i<=total_ticket;i++)
    {
        printf("\n\n Choose Seat Number :");
        scanf("%d",&j);
        if (j>100|j<1)
        {
            printf("Re_enter seat Number");
            scanf("%d",&j);
        }
        fp =fopen("avtSeat1.txt","a");
        if(fp==NULL)
        {
            printf("Error!!");
        }
        else
        {
            fprintf(fp,"%d ",j);
            printf("\n Record inserted\n");
            seat[i-1]=j;
        }
        printf("\n");
        fclose(fp);
        fclose(movi);
    }
    total_amount=b[count].cost * total_ticket;
    system("clear");
    printf("\n\t\t\t\t         ====================================MOVIE TICKET ==============================\n\n");
    printf("\t\t\t\t\t NAME          : %s                              MOVIE NAME      : %s   \n",name,b[count].name);
    printf("\t\t\t\t\t Mobile Number : %11lld                        Date            : %s    \n",mblnum,b[count].date);
    printf("\t\t\t\t\t                                                    Time            : %s   \n",b[count].time);
    printf("\t\t\t\t\t                                                    Total Seats     : %d    \n",total_ticket);
    printf("\t\t\t\t\t                                                    Cost Per Ticket : %dTk \n",b[count].cost);
    printf("\t\t\t\t\t                                                    Total Amount    : %d tk\n",total_amount);
    printf("\t\t\t\t\t                                                    Seat Number     : ");
    for(i=1;i<=total_ticket;i++)
    {
        printf("%d ",seat[i-1]);
    }
    printf("\n");
    printf("\t\t\t\t\t ******************************Booking Confirmed*********************************");
    fp=fopen("old_transc1.txt","a");
    if(fp==NULL)
    {
        printf("File Error!!");

    }
    else
    {
        fprintf(fp,"%s %lld %d %d %s %d %s %s \n",name,mblnum,total_ticket,total_amount,b[count].name,b[count].cost,b[count].date,b[count].time);
        //printf("\n Recorded \n");
        

    }
    printf("\n");
    fclose(fp);
    fclose(movi);



}

void old_trans(void)
{
    FILE *old;
    char ch;
    old=fopen("old_transc1.txt","r");
    if(old==NULL)
    {
        printf("File Does Not Exist>");
        exit(0);

    }
    else
    {
        while(!feof(old))
        {
            ch= fgetc(old);
            printf("%c",ch);

        }
    }
    fclose(old);
}





void seatplan(int n)
{

    if(n>100)
    {
        return;
    }
    else if(n<=100 && n%10!=0)
    {
        printf("%d\t",n);
        printf("+\t");
        //n++;
        return seatplan(n+1);

    }
    if(n%10==0)
    {
        printf("%d\t",n);
        printf("+");
        printf("\n\n");
        return seatplan(n+1);
    }
}
#endif //NEWPROJECT_MENU_H