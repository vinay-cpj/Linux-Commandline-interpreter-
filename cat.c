#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
int main( int argc,char **argv )
	{
	int fd,i;
    char buf[1024];
	char ch[1];
    void *line;
    if(argc>1){
	for(int i=1;i<argc;i++)	
	{
		fd=open(argv[i],O_RDONLY,0777);
		if(fd==-argc)
		{
			printf("file open error");
		}
		else
		{
			while((read(fd,ch,1))>0)
			{
				printf("%c",ch[0]);
			}
		close(fd);
		}
	}}
    else{
        while(1)
        {
            line=fgets(buf,1024,stdin);
            if(line==NULL)break;
            printf("%s",buf);
        }
    }
	return 0;
}

