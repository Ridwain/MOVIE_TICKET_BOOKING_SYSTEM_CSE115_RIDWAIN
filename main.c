//
// Created by Ridwain Islam on 16/12/22.
//
#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>
#include"splash.h"
#include"login.h"
#include"menu.h"


int main(void)
{
    splash();
    sleep(3);
    system("clear");
    int option=0;
    printf("\n  <1>   Register    ");
    printf("\n  <2>   Login       ");
    printf("\nEnter Your Choice  :");
    scanf("%d",&option);
    getchar();

    if(option==1)
    {
        start:
        system("clear");
        int new=reg();
        if(new==3)
        {
            fflush(stdin);
            option=2;
        }

    }
    if(option==2)
    {

        int fnc=login();
        if(fnc==1)
        {
            system("clear");
            menu();
        }
        if(fnc==2)
        {
            return 0;
        }
        if(fnc==4)
        {
            //system("clear");
            printf("Please register first :>\n\n\n");
            sleep(1);
            goto start;
        }

        }




    return 0;
}










