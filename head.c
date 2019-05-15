#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
int main(int argc, char**argv)
{
    int mode=0,i=1,num=10,fd,bytecount=0,mul=0,count=0;
    char ip[1];
    if(argv[1][0]=='-')
    {
        i=3;
        if(argv[1][1]=='c')
        {
            mode=1;
            num=atoi(argv[2]);
            if(argc>4)
                mul=1;
        }
        else if(argv[1][1]=='n')
        {
            mode=2;
            num=atoi(argv[2]);
            if(argc>4)
                mul=1;
        }
        else
        {
            mode=3;
            num=-1*atoi(argv[1]);
            i=2;
            if(argc>3)
                mul=1;
        }
    }
    else
    {
        if(argc>2)
            mul=1;
    }
    if(mode==1)
    {
        for(;i<argc;i++)
        {
            if(mul==1)
                printf("\n==> %s <==\n",argv[i]);
            bytecount=0;
            fd=open(argv[i],O_RDONLY);
            while((read(fd,ip,1))>0)
            {
                putchar(*ip);
                bytecount++;
                if(bytecount>=num)
                { 

                    break;
                }
            }
    }
    }
    else
    {
        for(;i<argc;i++)
        {
            count=0;
            if(mul==1)
                printf("\n==> %s <==\n",argv[i]);
            fd=open(argv[i],O_RDONLY);
            while((read(fd,ip,1))>0)
            {
                if(count==num)break;
                putchar(*ip);
                if(*ip=='\n')count++;
            }
    }

    }    
    return 0;
}
