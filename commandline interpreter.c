#define MAX 1024

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
    printf("\n######################### WELCOME TO VINAY COMMAND INTERPRETER ###################################\n");
    char ip[MAX];
    char *ip2;
    char *arg[32]; 
    int count=0,i=0,in=0,flag=0;
    while(1)
    {
        ip2=(char*)malloc(MAX);
        count=i=in=0;
        printf("$>");
        fflush(stdout);
        fgets(ip,MAX,stdin);
        if(!(strcmp(ip,"exit\n")))
        {
                exit(0);
        }
        for(i=0;i<strlen(ip);i++)
        {
            if(ip[i]==' '||ip[i]=='\n')
            {
                if(flag==0)continue;
                ip2[in]='\0';
                arg[count]=realloc(ip2,strlen(ip2)+1);
                ip2=(char*)malloc(MAX);
                count++;
                in=0;
                flag=0;
                continue;
            }
            ip2[in]=ip[i];
            in++;
            flag=1;
        }
        if(count==0)continue;
        arg[count]=NULL;
        pid_t pid;
        pid=vfork();
        if(pid==0)
        {
            if(!(strcmp(arg[0],"wc")))
            {
                 execvp("wc",arg);
                 exit(0);
            }
        
            else if(!(strcmp(arg[0],"ls")))
            {
                execvp("ls",arg);
                exit(0);
            }
            else if(!(strcmp(arg[0],"cat")))
            {
                execvp("cat",arg);
                exit(0);
            }
            else if(!(strcmp(arg[0],"rm")))
            {
                execvp("rm",arg);
                exit(0);
            }
            else if(!(strcmp(arg[0],"kill")))
            {
                execvp("kill",arg);
                exit(0);
            }
            else if(!(strcmp(arg[0],"head"))){
                execvp("head",arg);
                exit(0);
            }
            else {
                printf("Invalid Command Entered\n");
                exit(0);
        }
        }
        else{
          wait(NULL);
          for(i=0;i<=count;i++)
              free(arg[count]);
         }
    }
           

  return 0;
}

