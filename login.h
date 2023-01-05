//
// Created by Ridwain Islam on 24/12/22.
//

#ifndef PROJECTN_LOGIN_H
#define PROJECTN_LOGIN_H
struct login{
    char firstname[40];
    char lastname[40];
    char username[40];
    char password[10];
};


int login(void)
{
    char username[40],password[10];
    FILE *log;
    log = fopen("login1.txt","r");
    if(log == NULL)
    {
        printf("File can't be opened!!\n",stderr);
    }
   
    char line[140];
    system("clear");
    splash2();
    printf("\n\n\nPlease Enter your login credentials below\n\n");
    printf("Username:  ");
    fgets(username, 30, stdin);

    printf("\nPassword:  ");
    fgets(password, 20, stdin);
   

    int temp ;

    while(fgets(line,sizeof(line),log))
    {

        char Saved_Username[40]={'\0',};
        char Saved_Password[40]={'\0',};
        int i = 0, j = 0 ;
        temp = 0 ;
        for( ; i < sizeof(line) ; i++){
            if(temp == 2){
                if(line[i]!='\t'){
                    Saved_Username[j++] = line[i];
                }
                else {
                    Saved_Username[j] = '\n';
                    j = 0;
                }
            }
            else if(temp == 3){
                if(line[i]!='\n'){
                    Saved_Password[j++] = line[i];
                }
                else {
                    Saved_Password[j] = '\n';
                    
                    break;
                }
            }
            if(line[i] == '\t'){
                temp++;
            }
        }
        temp = 0;



        if(strcmp(username,Saved_Username)==0)
        {
            
            if ( strcmp(password,Saved_Password)==0){
                printf("\n\nSuccessful Login as %s\n", Saved_Username);
                return 1;
            }
            else {
                printf("Incorrect Password\n");
                return 2;
            }
        }

        
    }
    

    if(temp == 0){
        printf("This user is not registered\n");
        
        return 4;
    }

    fclose(log);
    return 5;

}


int reg(void) {

           FILE *log;
           log = fopen("login1.txt", "a");
           if (log == NULL) {
               printf("\n File Not Opened !! \n");
               exit(1);
           }

           struct login id;
           regist();
           printf("PLEASE ENTER YOUR FIRST NAME :");
           scanf("%s", id.firstname);
           printf("PLEASE ENTER YOUR LAST NAME :");
           scanf("%s", id.lastname);
           printf("PLEASE ENTER YOUR USER NAME :");
           scanf("%s", id.username);
           printf("PLEASE ENTER YOUR PASSWORD :");
           scanf("%s", id.password);
           fprintf(log, "%s\t%s\t%s\t%s\n", id.firstname, id.lastname, id.username, id.password);
           fclose(log);

           printf("Processing Information...\n....\nWelcome to Cineplex \n");
           printf("\n\n\t\t\t\tRegistration Successful\n");
           printf("\n\nProcessing Information...\n....\nWelcome to Cineplex \n");
           return 3;

       }


#endif //PROJECTN_LOGIN_H
