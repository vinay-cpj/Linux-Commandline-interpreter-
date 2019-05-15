#include<sys/types.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
int main(int argc,char ** argv){
    int i=1,opt=0,sig=9;
    pid_t pid;
    if(argv[1][0]=='-')
    {
        i=2;
        opt=1;
    }
    if(opt)
        sig=-1*atoi(argv[1]);

    for(;i<argc;i++)
    {
        pid=(pid_t)atoi(argv[i]);
        kill(pid,sig);
    }
    return 0;

}
